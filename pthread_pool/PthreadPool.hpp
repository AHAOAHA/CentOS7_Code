/*
 * 线程池
 */


#ifndef __PTHREAD_POOL_HPP__
#define __PTHREAD_POOL_HPP__

#include<iostream>
#include<pthread.h>
#include<queue>

using namespace std;


class Task
{
  typedef int (*cal_t)(int, int);
  public:
  Task(int x, int y, cal_t handler)
    :_handler(handler)
     ,_x(x)
     ,_y(y)
  {}

  int Run()
  {
    int ret =  _handler(_x, _y);
    return ret;
  }

  private:
  cal_t _handler;
  int _x;
  int _y;

};



class ThreadPool
{
  public:
    ThreadPool(int num = 5):_threadNum(num)
    {}


    ~ThreadPool()
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&cond);
    }

    void ThreadInit()//创建线程，并将线程存进queue
    {

      pthread_mutex_init(&lock, NULL);//初始化互斥锁
      pthread_cond_init(&cond, NULL);//初始化条件变量

      for(int i = 0; i < _threadNum; ++i)
      {
        pthread_t tid;
        pthread_create(&tid, NULL, start_routine, (void*)this);
      }
    }

    void PushTask(Task& t)
    {
      //当主线程向队列中添加任务时，应当为临界资源加锁
      LockQueue();

      if((int)_task_queue.size() == _threadNum)
      {
        //如果任务队列中队列已经满了，则不能添加此处任务，应当释放锁并退出
        UnlockQueue();
        return;
      }
      _task_queue.push(t);
      UnlockQueue();
      //主线程添加任务完毕，应当给正在条件变量队列中等待任务的一个进程发送信号
      pthread_cond_signal(&cond);
    }


  private:
    static void* start_routine(void *arg)
    {
      //主线程不需要等待其他线程，则这里进行线程分离
      pthread_detach(pthread_self());
      ThreadPool* tp = (ThreadPool*)arg;
      for(;;)
      {
        //因为_task_queue是所有线程共享的临界资源，所以访问临界资源时必须加锁
        tp->LockQueue();

        while(tp->Empty())
        {
          //如果任务队列为空，则线程释放锁，并去条件变量队列中排队等候
          pthread_cond_wait(&tp->cond, &tp->lock);
        }

        //程序运行到这里时，说名任务队列中已经存在任务
        Task t = tp->_task_queue.front();
        tp->_task_queue.pop();

        //当线程拿到一个任务之后，即将要去执行任务，这时可以释放锁，让其他进程继续来检测任务
        tp->UnlockQueue();

        t.Run();

      }
    }

    void UnlockQueue()
    {
      pthread_mutex_unlock(&lock);
    }

    void LockQueue()
    {
      pthread_mutex_lock(&lock);
    }

    bool Empty()
    {
      return _task_queue.size() == 0;
    }

  private:
    int _threadNum;//线程池中线程的个数
    queue<Task> _task_queue;//存放线程池的队列
    

    pthread_mutex_t lock;
    pthread_cond_t cond;
};


#endif

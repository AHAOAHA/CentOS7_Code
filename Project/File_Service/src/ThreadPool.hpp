/*************************************************************************
*File Name: ThreadPool.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年02月19日 星期二 09时47分28秒
 ************************************************************************/
#pragma once
#include <iostream>
#include <queue>
#include <pthread.h>
#define LOG(...) do{\
        fprintf(stdout, __VA_ARGS__);fflush(stdout);\
        }while(0);

class ThreadPool
{
	//线程池类
	//创建指定数量的线程
	//创建一个线程安全的任务队列
	//提供任务队列的入队，出队，线程池销毁/初始化接口
	private:
		int _max_thr;	//当前线程池中的最大线程数
   	int _cur_thr;	//当前线程池中的线程数
    bool _is_stop;
		std::queue<Http:Task> _task_queue;
		pthread_mutex_t _mutex;
		pthread_cond_t _cond;
	private:
		static void* thr_start(void* arg)
    {
      //完成线程获取任务，并执行任务
      ThreadPool* tp = (ThreadPool*)arg;
      tp->QueueLock();
      while(tp->QueueIsEmpty())
      {
        tp->ThreadWait();
      }
      HttpTask ht;
      tp->PopTask(ht);
      tp->QueueUnlock();
      ht.Handler();
      return NULL;
    }
  private:
    void QueueLock()
    {
      pthread_mutex_lock(&_mutex);
    }
    void QueueUnlock()
    {
      pthread_mutex_unlock(&_mutex);
    }
    bool IsStop()
    {
      return _is_stop;
    }
    void ThreadExit()
    {
      _cur_thr--;
      pthread_exit(NULL);
    }
    void ThreadWait()
    {
      if(IsStop())
      {
        //若线程池要销毁，则无需等待，解锁之后直接退出
        QueueUnlock();
        ThreadExit();
      }
      pthread_cond_wait(&_cond, &_mutex);
    }
    void ThreadWakeUpOne()
    {
      pthread_cond_signal(&_cond);
    }
    void ThreadWakeUpAll()
    {
      pthread_cond_broadcast(&_cond);
    }
    bool QueueIsEmpty()
    {
      return _task_queue.empty();
    }
	public:
		ThreadPool(int max): _max_thr(max), _cur_thr(0)
		{}
    ~ThreadPool()
    {
      pthread_mutex_destroy(&_mutex);
      pthread_cond_destroy(&_cond);
    }

		bool ThreadPoolInit()	//完成线程创建以及互斥锁和条件变量的初始化
    {
      pthread_t tid;
      for(int i = 0; i < _max_thr; ++i)
      {
        int ret = pthread_create(&tid, NULL, thr_start, this);
        if(ret != 0)
        {
          LOG("thread create error\n");
          return false;
        }

        pthread_detach(tid);
        _cur_thr++;
      }

      //初始化
      pthread_mutex_init(&_mutex, NULL);
      pthread_cond_init(&_cond, NULL);

    }
		bool PushTask(HttpTask &tt)
    {
      //线程安全的任务入队
      //lock
      QueueLock();
      _task_queue.push(tt);
      //unlock
      QueueUnlock();
    }
		bool PopTask(HttpTask &tt)
    {
      //线程安全的任务出队，因为任务出队是在线程接口中调用
      //但是线程接口中在出队之前就会进行加锁，因此这里不需要加锁
      tt = _task_queue.front();
      _task_queue.pop();
    }
		bool ThreadPoolStop()
    {
      //销毁线程池
      if(!IsStop())
      {
        _is_stop = true;
      }
      while(_cur_thr < 0)
      {
        ThreadWakeUpAll();
        usleep(1000);
      }
      return true;
    }
};

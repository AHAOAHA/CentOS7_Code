/*************************************************************************
*File Name: PthreadPool.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月08日 星期二 22时39分41秒
 ************************************************************************/
#include <pthread.h>
#include <queue>
#include <pthread.h>
#include "Task.hpp"

class PthreadPool
{
  public:
    PthreadPool(int num):_num(num)
    {
      pthread_mutex_init(&_lock, NULL);
      pthread_cond_init(&_cond, NULL);
    }

    void PthreadPoolInit()
    {
      size_t i = 0;
      for(i  = 0; i < _num; ++i)
      {
        pthread_t id;
        pthread_create(&id, NULL, StartRoutine, (void*)this);
      }
    }

    static void* StartRoutine(void* arg)
    {
      pthread_detach(pthread_self());
      PthreadPool* self = (PthreadPool*)arg;

      for(;;)
      {
        pthread_mutex_lock(&self->_lock);
        while(self->_tq.empty() == true)
        {
          pthread_cond_wait(&self->_cond, &self->_lock);
        }
        std::cout << "thread: "<< pthread_self() << " get a client, client fd: " << self->_tq.front().fd()<< std::endl;

        Task t = self->_tq.front();
        self->_tq.pop();
        pthread_mutex_unlock(&self->_lock);

        t.Run();

      }
      return NULL;

    }

    void AddTask(Task& t)
    {
      pthread_mutex_lock(&_lock);
      _tq.push(t);
      pthread_mutex_unlock(&_lock);
      pthread_cond_signal(&_cond);
    }

    ~PthreadPool()
    {}

  private:
    size_t _num;//线程池中线程的数量
    pthread_mutex_t _lock;
    pthread_cond_t _cond;
    std::queue<Task> _tq; 
};

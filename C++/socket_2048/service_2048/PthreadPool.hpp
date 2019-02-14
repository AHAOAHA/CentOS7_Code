/*************************************************************************
*File Name: PthreadPool.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年02月08日 星期五 20时26分23秒
 ************************************************************************/
#pragma once
#include <pthread.h>
#include <queue>
#include "service.hpp"
#include "Task.hpp"

class PthreadPool
{
  public:
    PthreadPool(size_t num):_num(num)
    { 
      //构造函数
    }

    //线程进入函数
    static void* StartRoutine(void* arg)
    {
      pthread_detach(pthread_self());

      PthreadPool* self = (PthreadPool*)arg;

      //线程主体流程
      for(;;) 
      {
        pthread_mutex_lock(&self->_lock);
        while(self->_tq.empty())
        {
          pthread_cond_wait(&self->_cond, &self->_lock);
        }

        Task t = self->_tq.front();
        self->_tq.pop();
        pthread_mutex_unlock(&self->_lock);

        t.Run();
      }
      return nullptr;
    }

    void AddTask(Task& t)
    {
      //添加任务
      pthread_mutex_lock(&_lock);
      _tq.push(t);
      pthread_mutex_unlock(&_lock);
      pthread_cond_signal(&_cond);
      
    }

    void PthreadInit()
    {
      pthread_mutex_init(&_lock, nullptr);
      pthread_cond_init(&_cond, nullptr);

      pthread_t id;
      size_t i = 0;
      //此处创建线程
      for(i = 0; i < _num; ++i)
      {
        pthread_create(&id, nullptr, StartRoutine, (void*)this);
      }
    }

    ~PthreadPool()
    {
      //析构函数
    }
  private:
    //线程池中线程的数量
   size_t _num;
   pthread_mutex_t _lock;
   pthread_cond_t _cond;
   std::queue<Task> _tq;
};

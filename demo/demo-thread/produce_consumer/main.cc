/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Sat 08 Dec 2018 11:29:21 PM CST
 ************************************************************************/

/*
 * 线程版本实现生产者消费者模型
 */
#include<iostream>
#include<queue>
#include<unistd.h>
#define MAXSIZE 5
std::queue<int> q;
pthread_mutex_t mutex;
pthread_cond_t cond;
int i = 0;
void* Produce_Start(void *arg)
{
  while(1)
  {
    pthread_mutex_lock(&mutex);
    while(q.size() >= MAXSIZE)
    {
      pthread_cond_signal(&cond);
      pthread_cond_wait(&cond, &mutex);
    }

    q.push(i++);

    std::cout << "Produce doing ... " << i<< " i am " << pthread_self() << std::endl;
    sleep(1);
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
    usleep(1000);
  }
  return arg;
}

void Produce()
{
  pthread_t id;
  pthread_create(&id, nullptr, Produce_Start, nullptr);
  pthread_detach(id);
}


void *ConsumeStart(void* arg)
{
  while(1)
  {
    pthread_mutex_lock(&mutex);
    while(q.size() == 0)
    {
      pthread_cond_signal(&cond);
      pthread_cond_wait(&cond, &mutex);
    }

    std::cout << "Consume doing ..." << q.front() << std::endl;
    q.pop();
    sleep(1);

    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
    usleep(100000);
  }

  return arg;
}

void Consume()
{
  pthread_t id;
  pthread_create(&id, nullptr, ConsumeStart, nullptr);
  pthread_detach(id);
}
void testProCon()
{
  Produce();
  Consume();
}

int main()
{
  pthread_mutex_init(&mutex, nullptr);
  pthread_cond_init(&cond, nullptr);
  testProCon();
  while(1)
  {
    ;
  }
  return 0;
}

/* 
 * 线程接口熟悉
 */

#include<pthread.h>
#include<iostream>
#include<unistd.h>
using namespace std;

void* rontine_start(void *arg)
{
  size_t count = 10;
  while(count--)
  {
    cout<< "pthread is runnning..."<<endl;
    sleep(1);
  }
  return arg;
}

int main()
{
  pthread_t id;
  void *arg = nullptr;
  pthread_create(&id, nullptr, rontine_start, (void*)arg);
  pthread_detach(id);

  while(1);
  return 0;
}

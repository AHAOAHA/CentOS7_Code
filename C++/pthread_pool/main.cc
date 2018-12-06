#include"PthreadPool.hpp"

#include<unistd.h>

int add(int x, int y)
{
  while(1)
  {
    std::cout<< "thread "<<pthread_self()<<" is runing..."<<std::endl;
    sleep(1);
  }
  return x+y;
}
int main()
{
  int count = 100;
  ThreadPool tp(6);
  tp.ThreadInit();
  while(count)
  {
    Task t(count,count+1, add);
    tp.PushTask(t);
    sleep(1);
    count--;
  }
  return 0;
}

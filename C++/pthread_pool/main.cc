#include"PthreadPool.hpp"

#include<unistd.h>

int add(int x, int y)
{
  return x+y;
}
int main()
{
  int count = 0;
  ThreadPool tp(1);
  tp.ThreadInit();
  while(1)
  {
    Task t(count,count++, add);
    tp.PushTask(t);
    sleep(1);
  }
  return 0;
}

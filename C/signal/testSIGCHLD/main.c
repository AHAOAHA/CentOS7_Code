/*
 * 验证子进程退出时向父进程发送SIGCHLD信号
 */


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void showpending(const sigset_t* set)
{
  int i = 0;
  for(i = 0; i< 32; ++i)
  {
    if(1 == sigismember(set, i))
      printf("1");
    else
      printf("0");
  }

  printf("\n");

}
int main()
{
  pid_t id = fork();
  if(-1 == id)
  {
    exit(-1);
  }
  else if(0 == id)
  {
    int i = 5;
    while(i--)
    {
      printf("i am child...\n");
      sleep(1);
    }
    exit(-1);
  }
  else
  {
    sigset_t set;
    sigset_t newblock;
    sigemptyset(&newblock);
    sigaddset(&newblock, SIGCHLD);
    sigaddset(&newblock, 2);
    sigprocmask(SIG_SETMASK, &newblock, NULL);
    sigemptyset(&set);
    while(1)
    {
      sigpending(&set);
      showpending(&set);
      sleep(1);
    }
  }
  return 0;
}

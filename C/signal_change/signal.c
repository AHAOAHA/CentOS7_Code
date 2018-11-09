#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int signo)
{
  printf("signo: %d, time up...\n", signo);
}
int main()
{
  signal(14, handler);
  alarm(5);
  while(1)
  {
    printf("pid: %d\n", getpid());
    sleep(1);
  }
  return 0;
}

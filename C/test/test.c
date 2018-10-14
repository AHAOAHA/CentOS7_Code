#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
/*
int main()
{
  pid_t id=fork();
  if(0 == id)//子进程
  {
    sleep(3);
    exit(1);
  }
  else//父进程
  {
    int st;
    while(wait(&st)==id);
    int i=16;
    while(i--)
    {
      printf("%d ",st^1);
      st>>=1;
    }
  }
  return 0;
}
*/


int main()
{
  system("ls -a");
  return 0;
}

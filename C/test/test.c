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

/*
void fun1()
{
  while(1);
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
  
  int count = 100;
  while(count--)
  {
    printf("hello world\n"); 
  }
  
  char cmd[20];
  scanf("%s",cmd);
  system(cmd);
  return 0;
}
*/
#include"test.h"
void test()
{
  printf("hello\n");
}

#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>



void test(void* p)
{
  printf("%d\n",*(int*)p);
 
}
void process_create(pid_t* pid,void* func,void* arg)
{
  
  typedef void (*PFunc)(void* arg);
  *pid = fork();
  if(-1 == *pid)//进程创建失败
  {
    exit(0);
  }
  else if(0 == *pid)//子进程
  {
    if(NULL == func)
    {
      exit(0);
    } 
  ((PFunc)func)(arg);//执行目标函数
    exit(0);
  }
  else//父进程
  {
    int st;
    while(wait(&st) == *pid);
  }
}


int main()
{
  pid_t pid;
  int i=1;
  process_create(&pid,test,&i);
  sleep(3);
  printf("子进程执行完毕\n");
  return 0;
}

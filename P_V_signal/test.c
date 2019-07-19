#include"./my_sem.h"
int main()
{
  int semid = CreatSem(1);//创建包含一个信号量的信号集
  InitSem(semid, 0, 1);//初始化所创建的信号集,这里用1初始化是因为第一次使用信号量时，他所对应的对象应该是可以访问的
  pid_t id = fork();
  if(-1 == id)
  {
    exit(EXIT_FAILURE);
  }
  else if(0 == id)
  {
    int i =1000;
    while(i--)
    {
      P(semid);//子进程对信号量集进行P操作
      printf("A");
      fflush(stdout);
      usleep(12345);
      printf("A ");
      fflush(stdout);
      usleep(12378);
      V(semid);//子进程对信号量集合进行V操作
    }
  }
  else
  {
    int i = 1000;
    while(i--)
    {
      P(semid);//父进程对信号量集进行P操作
      printf("B");
      fflush(stdout);
      usleep(13456);
      printf("B ");
      fflush(stdout);
      usleep(13487);
      V(semid);//父进程对信号量集进行V操作
    }


    while(wait(NULL) != id);//等待子进程退出
    DestorySem(semid);//销毁信号量集
  }
  return 0;
}

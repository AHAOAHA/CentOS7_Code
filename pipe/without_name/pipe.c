/*
 * 实现父进程与子进程之间的通信
 * 采用匿名管道的方式
 * 测试用例：
 *    子进程相管道内写入数据
 *    父进程从管道内拿出数据
 *    
 * 遇到的问题：
 *    1.pipe(int fd[2]);创建管道函数不能写在fork()；函数的后面
 *    2.当子进程向管道写入数据之后立刻退出并关闭写端，父进程一直从管道中读取数据，此时管道
 *      内的数据会被重复读取
 *      
 * 未解决问题：
 *    1.当匿名管道写满之后，父进程读出数据，子进程没有继续写入
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

void test_pipe()
{
  int fd[2];
  if(pipe(fd) == -1)//匿名管道打开失败
  {
    printf("管道创建失败！\n");
    exit(EXIT_FAILURE);
  }

  pid_t id = fork();//确保子进程先运行
  char buf[64];
  if(-1 == id)//创建子进程失败
  {
    printf("创建子进程失败！\n");
    exit(-1);
  }
  else if(0 == id)//子进程
  {
    int i = 0;
    close(fd[0]);//关闭子进程的读端
    strcpy(buf, "hello, i am child...\n");
    while(i < 10)
    {
      i += 1;
      write(fd[1], buf, sizeof(buf));
    }
    while(1);
    close(fd[1]);

    
  }
  else//父进程
  {
    close(fd[1]);
    while(1)
    {

      read(fd[0], buf, sizeof(buf));
      printf("%s",buf);
      fflush(stdout);
      sleep(1);
    }
  
    while(wait(NULL)!=id);
    close(fd[0]);
  }
}
int main()
{
  test_pipe();
  return 0;
}

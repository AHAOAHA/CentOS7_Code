#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void printsigset(const sigset_t* p)
{
  int i = 32;
  for(i = 0; i < 32; ++i)
  {
    if(sigismember(p, i))//查看信号表中是否含有i位置的信号，pending/block 
      putchar('1');
    else
      putchar('0');
  }

  printf("\n");
}
int main()
{
  alarm(10);//设置闹钟，使进程10秒后收到14号信号
  sigset_t s, p;//定义两个位图，p位图用来保存信号的pending表，s位图用来设置该进程的block表
  sigemptyset(&s);//将s位图全部置为0
  sigaddset(&s, 2);//将s位图的2号位置置为1,将2号信号阻塞
  sigaddset(&s, 14);//将14号信号阻塞
  sigprocmask(SIG_BLOCK, &s, NULL);//用s位图给该进程的block表赋值，即就是将该进程的block表换成事先设置号的s位图
  while(1)
  {
    sigpending(&p);//将该进程的pending表赋给p位图，p位图可以实时表示该进程的pending表
    printsigset(&p);//设置函数打印出p位图中的值
    sleep(1);
  }

  return 0;
}

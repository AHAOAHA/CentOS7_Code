/*
 * 实现自己的sleep函数
 */

#include<unistd.h>
#include<signal.h>
#include<stdio.h>

int mysleep(unsigned int seconds);





void hander(int signo)
{}


int mysleep(unsigned int seconds)
{
  struct sigaction new, old;//使用结构体来设置信号处理函数，new用来设置新的信号处理函数。old用来保存旧的信号处理函数
  new.sa_handler = hander;
  int unslept = 0;
  sigisemptyset(&new.sa_mask);
  new.sa_flags = 0;
  sigaction(14, &new, &old);//使用该函数来注册信号处理函数
  alarm(seconds);//设置闹钟
  pause();//挂起本进程
  unslept = alarm(0);


  sigaction(14, &old, NULL);//在mysleep函数使用完成之后，要将14号信号的处理动作更改为默认之前的动作，如果不改变，在进程接下来的生命周期里，如果收到了14号信号，则进程的处理动作依然是本次注册的14号信号处理函数
  return 0;
}

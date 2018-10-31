#include"../pipe.h"

int main()
{
  int fd;
  char buf[BUF_SIZE] = {0};
  umask(0);
  mkfifo("/tmp/PIPE_SERVICE", 0644);

  fd = open("/tmp/PIPE_SERVICE", O_RDONLY);//打开管道
    while(1)
    {
      ssize_t s;
      printf("Please wait...\n");
      s = read(fd, buf, sizeof(buf));
      if(s <= 0)
      {
        break;
      }
      //sleep(3);
      if(0 == strcmp(buf,"quit\n"))//客户端向服务端发送退出信号
      {
        printf("quit signal,Bye...\n");
        break;
      }
      printf("client$ %s",buf);
      fflush(stdout);
    }
  
  close(fd);//关闭管道

  return 0;
}

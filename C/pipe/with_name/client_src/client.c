#include"../pipe.h"

int main()
{
  int fd;
  char buf[1024] = {0};


  fd = open("/tmp/PIPE_SERVICE", O_WRONLY);//打开管道
  int i = 100;
  while(i--)
  {
    printf("client# ");
    fflush(stdout);
    fgets(buf, sizeof(buf), stdin);
    write(fd, buf, sizeof(buf));

  }
  close(fd);//关闭服务端管道

  return 0;
}

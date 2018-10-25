#include"../pipe.h"

int main()
{
  int fd;
  int buf[1024];
  umask(0);
  mkfifo("../PIPE_NAME", 0644);

  fd = open("../PIPE_NAME", O_RDONLY);//打开管道

  while(1)
  {
    read(fd, buf, sizeof(buf));
    printf("client$ %s",buf);
  }
  close(fd);//关闭管道


  return 0;
}

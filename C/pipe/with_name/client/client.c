#include"../pipe.h"

int main()
{
  int fd;
  int buf[1024] = {0};

  fd = open("../PIPE_NAME", O_WRONLY);//打开管道

  while(1)
  {
    printf("client# ");
    fflush(stdout);
    read(0, buf, sizeof(buf));
    write(fd, buf, sizeof(buf));
    
  }
  close(fd);//关闭管道


  return 0;
}

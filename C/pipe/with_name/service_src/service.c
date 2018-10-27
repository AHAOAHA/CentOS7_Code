#include"../pipe.h"

int main()
{
  int fd;
  char buf[1024] = {0};
  umask(0);
  mkfifo("/tmp/PIPE_SERVICE", 0644);

  fd = open("/tmp/PIPE_SERVICE", O_RDONLY);//打开管道
    while(1)
    {
      ssize_t s;
      s = read(fd, buf, sizeof(buf));
      //sleep(3);
      if(0 == strcmp(buf,"quit\n"))
      {
        break;
      }
      if(s > 0)
      {
        printf("client$ %s",buf);
        fflush(stdout);
      }
      else if(s == 0)
        break;
    }
  
  close(fd);//关闭管道

  return 0;
}

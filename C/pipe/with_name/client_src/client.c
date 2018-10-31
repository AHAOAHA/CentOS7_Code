#include"../pipe.h"

int main()
{
  int fd;
  char buf[BUF_SIZE] = {0};


  fd = open("/tmp/PIPE_SERVICE", O_WRONLY);//打开管道
  while(1)
  {
    printf("client# ");
    fflush(stdout);
    fgets(buf, sizeof(buf), stdin);
    write(fd, buf, sizeof(buf));
    if(0 == strcmp(buf, "quit\n"))
    {
      printf("Bye...\n");
      break;
    }
  }
  close(fd);//关闭服务端管道

  return 0;
}

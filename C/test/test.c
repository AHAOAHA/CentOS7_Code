#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
  int fd;
  char buf[32] = "hello";
  fd = open("/dev/pts/0", O_WRONLY);
  int ret;
  while(1)
  {
    ret = write(fd, buf, sizeof(buf));
    sleep(1);
    //printf("%d\n", ret);
  }
  return 0;
}

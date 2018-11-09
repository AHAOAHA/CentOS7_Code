#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<errno.h>
int main()
{
  printf("%d\n", errno);
  printf("%s\n", strerror(1));
  return 0;
}

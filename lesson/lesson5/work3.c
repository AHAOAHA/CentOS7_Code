/*************************************************************************
*File Name: work3.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 25 Dec 2018 12:31:20 PM CST
 ************************************************************************/
//实现最多能输入3次密码的模式
#include <stdio.h> 
#include <string.h>


int main()
{
  const char *sec = "123456"; 
  char buf[1024] = {'\0'};
  printf("you have 3 times ...\n");
  int count = 3;
  while(count--)
  {
    printf("input:");
    memset(buf, '\0', sizeof(buf));
    fgets(buf, sizeof(buf) - 1, stdin);
    setbuf(stdin, NULL);
    buf[strlen(buf) - 1] = '\0';
    if(0 == strcmp(buf, sec))
    {
      printf("do something ...\n");
      break;
    }
    else
    {
      printf("you just have %d times ...\n", count);
    }
  }

  return 0;
}

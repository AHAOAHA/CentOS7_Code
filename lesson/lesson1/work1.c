/*************************************************************************
*File Name: work1.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 03:30:06 PM CST
 ************************************************************************/
// 打印1~200之间的素数


#include <stdio.h>

int main()
{
  int num = 1;
  int i = 1;
  printf("1~100之间的素数:");
  for(num = 1; num <= 100; ++num)
  {
    for(i = 2; i < num; ++i)
    {
      if(num % i == 0)
      {
        break;
      }
    }

    if(i == num)
    {
      printf("%d ", num);
    }
  }
  printf("\n");
  return 0;
}

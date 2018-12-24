/*************************************************************************
*File Name: work3.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 04:56:04 PM CST
 ************************************************************************/
//编写程序计算1~99出现多少次9
#include <stdio.h>

int main()
{
  int num = 1;
  int tmp;
  static int count = 0;
  for(num = 1; num < 100; ++num)
  {
    tmp = num;
    
    while(tmp > 0)
    {
      if(tmp % 9 == 0)
      {
        count++;
      }

      tmp /= 10;
    }
  }

  printf("count = %d\n",  count);
  return 0;
}

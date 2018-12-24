/*************************************************************************
*File Name: work2.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 04:41:17 PM CST
 ************************************************************************/
//计算1/1-1/2+1/3-1/4...+1/99-1/100的值
#include <stdio.h>

int main()
{
  double sum = 0;
  int i = 1;
  double tmp;
  for(i = 1; i <= 100; ++i)
  {
    if(i % 2 == 0)
    {
      tmp = -1 * 1/i;
    }
    else
    {
      tmp = 1/i;
    }

    sum += tmp;
  }

  printf("sum = %f\n", sum);
  return 0;
}

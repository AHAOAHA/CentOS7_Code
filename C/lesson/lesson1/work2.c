/*************************************************************************
*File Name: work2.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 03:34:56 PM CST
 ************************************************************************/
//出乘法口诀表
#include <stdio.h> 

int main()
{
  int i = 0;
  int j = 0;

  for(i = 1; i < 10; ++i)
  {
    for(j = 1; j <= i; ++j)
    {
      printf("%d*%d=%-2d ", i, j , i*j);
    }
    printf("\n");
  }
  return 0;
}

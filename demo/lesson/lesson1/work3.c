/*************************************************************************
*File Name: work3.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 03:35:09 PM CST
 ************************************************************************/
//判断1000~2000年之间的闰年
#include <stdio.h>

int main()
{
  int year = 1000;
  printf("1000~2000年之间的闰年:");
  for(year  = 1000; year <= 2000; ++year)
  {
    if(((year % 4 == 0) && (year % 100 != 0)) || \
        (year % 400 == 0))
    {
      printf("%d ", year);
    }
  }
  printf("\n");
  return 0;
}

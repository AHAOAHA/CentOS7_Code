/*************************************************************************
*File Name: work3.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月13日 星期日 23时24分26秒
 ************************************************************************/
//判断是不是闰年
#include <stdio.h>

int IsLeapYear(int year)
{
  if((year % 400 == 0) ||\
      ((year % 4 == 0 ) && (year % 100 != 0)))
  {
    return 1;
  }
  return 0;
}


int main()
{
  int year = 0;
  printf("year: ");
  scanf("%d", &year);
  int ret = IsLeapYear(year);
  if(ret == 1)
  {
    printf("Is Leap Year ...\n");
  }
  else
  {
    printf("Is Not Leap Year...\n");
  }
  return 0;
}

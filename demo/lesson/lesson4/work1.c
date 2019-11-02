/*************************************************************************
*File Name: work1.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 06:51:35 PM CST
 ************************************************************************/
/* 
 * 打印下面的图像
 * *
 * ***
 * *****
 * ...
 */
#include <stdio.h>

int main()
{
  int hight = 0;
  int i;
  int j = 0;
  printf("half hight +1:");
  scanf("%d", &hight);

  for(i = 0; i < hight; ++i)
  {
    for(j = 0; j < 2*i+1; ++j)
    {
      printf("*");
    }
    printf("\n");
  }

  for(i = i - 2; i >= 0; --i)
  {
    for(j = 0; j < 2*i+1; ++j)
    {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}

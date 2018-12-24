/*************************************************************************
*File Name: work3.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 04:02:11 PM CST
 ************************************************************************/
//求10个数中最大的数
//求输入数据中最大的数
#include <stdio.h>

int main()
{
  int max;
  int size;
  int tmp;
  int i;
  printf("size = ");
  scanf("%d", &size);

  for(i = 0; i < size; ++i)
  {
    if(i == 1)
    {
      scanf("%d", &max);
    }
    else
    {
      scanf("%d", &tmp);
      if(tmp > max)
      {
        max = tmp;
      }
    }
  }
  printf("max = %d\n", max);


  return 0;
}

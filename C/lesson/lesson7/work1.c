/*************************************************************************
*File Name: work1.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月13日 星期日 21时40分34秒
 ************************************************************************/
//打印乘法口诀表，行数自行定义
#include <stdio.h>

int main()
{
  int i = 0;
  int j = 0;
  int col;
  printf("COL: ");
  scanf("%d", &col);
  for(i = 1; i <= col; ++i)
  {
    for(j = 1; j <= i; ++j)
    {
      printf("%-d*%-d=%-4d ", j,i,j*i);
    }
    printf("\n");
  }
  return 0;
}

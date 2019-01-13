/*************************************************************************
*File Name: work2.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月13日 星期日 21时52分20秒
 ************************************************************************/
//使用函数实现两个数的交换
#include <stdio.h>

void swap1(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap2(int *a, int *b)
{
  *a = *a + *b;
  *b = *a - *b;
}
int main()
{
  int a = 3;
  int b = 5;
  printf("a = %d, b = %d\n", a, b);
  swap1(&a, &b);
  printf("a = %d, b = %d\n", a, b);
  return 0;
}

/*************************************************************************
*File Name: work1.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 03:49:57 PM CST
 ************************************************************************/
//交换两个整型变量的值
#include <stdio.h>

//first
void swap1(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

//second
//缺点:当a+b的值大于INT_MAX时会造成数据溢出
void swap2(int *a, int *b)
{
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

//third
//不会造成second方法中的数据溢出
void swap3(int *a, int *b)
{
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

int main()
{
  int a = 3;
  int b = 5;
  printf("%d, %d\n", a, b);
  swap1(&a, &b);
  printf("%d, %d\n", a, b);
  printf("%d, %d\n", a, b);
  swap2(&a, &b);
  printf("%d, %d\n", a, b);
  printf("%d, %d\n", a, b);
  swap3(&a, &b);
  printf("%d, %d\n", a, b);
  
  return 0;
}

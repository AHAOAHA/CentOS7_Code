/*************************************************************************
*File Name: work3.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 07:05:42 PM CST
 ************************************************************************/
//求Sn=a+aa+aaa+aaaa...的前n项和
#include <stdio.h>
#include <math.h>
int main()
{
  int num = 0;
  int n = 0;
  int i;
  int sum = 0;
  printf("num = ");
  scanf("%d", &num);
  printf("n = ");
  scanf("%d", &n);

  for(i = 0; i < n; ++i)
  {
    sum += (num * (int)pow((double)10, (double)(i)) + sum);
  }

  printf("Sn = %d\n", sum);
  return 0;
}

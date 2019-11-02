/*************************************************************************
*File Name: work5.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月14日 星期一 11时54分53秒
 ************************************************************************/
//判断一个数是不是素数
#include <stdio.h>

int IsPrime(int val)
{
  int i = 2;
  for(i; i < val; ++i)
  {
    if(val % i == 0)
    {
      printf("Is Not Prime...\n");
      return 0;
    }
  }
  printf("Is Prime...\n");
  return 0;
}

int main()
{
  int val;
  printf("val: ");
  scanf("%d", &val);
  IsPrime(val);
  return 0;
}

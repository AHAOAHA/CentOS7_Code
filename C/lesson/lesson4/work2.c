/*************************************************************************
*File Name: work2.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 06:54:54 PM CST
 ************************************************************************/
//求出0~999之间所有的水仙花数并输出。"水仙花数"指一个三位数个数字的立方刚好等于这个数字
#include <stdio.h>
#include <math.h>

int main()
{
  int num  =0;
  int tmp;
  int sum = 0;
  printf("水仙花数:");
  for(num = 100; num < 1000; ++num)
  {
    tmp = num;
    sum = 0;
    while(tmp > 0)
    {
      sum += (int)pow((double)(tmp%10), (double)3);
      tmp /= 10;
    }

    if(sum == num)
    {
      printf("%d ", num);
    }
  }

  printf("\n");
  return 0;
}

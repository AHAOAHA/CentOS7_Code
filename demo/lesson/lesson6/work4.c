/*************************************************************************
*File Name: work4.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月13日 星期日 21时27分12秒
 ************************************************************************/
//输出两个整数的二进制位中有多少个不同的比特位
#include <stdio.h>

size_t CountDifBit(int val1, int val2)
{
  int val = val1 ^ val2;
  size_t i = 0;
  size_t count = 0;
  for(i = 0; i < 32; ++i)
  {
    if((val & (1 << i)) == 0)
    {
      ;
    }
    else
    {
      ++count;
    }
  }
  return count;
}

int main()
{
  int val1;
  int val2;
  printf("val1: ");
  scanf("%d", &val1);
  printf("val2: ");
  scanf("%d", &val2);

  int ret = CountDifBit(val1, val2);
  printf("DifCount: %d\n", ret);

  return 0;
}

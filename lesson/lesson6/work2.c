/*************************************************************************
*File Name: work2.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 25 Dec 2018 01:55:57 PM CST
 ************************************************************************/
//分别获取一个整型的奇数二进制位和偶数二进制位
#include <stdio.h>

void saveBit(char *buf, char *bufJ, char *bufO, int val)
{
  int i = 0;
  for(i =0; i < 32; ++i)
  {
    if((val & (1 << i)) == 0)
    {
      buf[31 - i] = '0';
    }
    else
    {
      buf[31 - i] = '1';
    }
  }

  size_t j = 0;
  for(i = 0; i < 32; i+=2)
  {
    bufO[j] = buf[i];
    ++j;
  }

  j=0;
  for(i = 1; i < 32; i+=2)
  {
    bufJ[j] = buf[i];
    ++j;
  }
}

int main()
{
  int val;
  char buf[33] = {'\0'};
  char bufJ[17] = {'\0'};
  char bufO[17] = {'\0'};
  printf("val:");
  scanf("%d", &val);
  saveBit(buf, bufJ, bufO, val);
  puts(buf);
  puts(bufJ);
  puts(bufO);

  return 0;
}

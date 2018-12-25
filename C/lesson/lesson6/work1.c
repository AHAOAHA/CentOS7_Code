/*************************************************************************
*File Name: work1.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 25 Dec 2018 01:16:58 PM CST
 ************************************************************************/
//返回参数中数字的二进制形式
#include <stdio.h>
#include <stdlib.h>
void swap(char *a, char *b)
{
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void resever(char buf[], size_t size)
{
  int left = 0;
  int right = size-1;
  while(left < right)
  {
    swap(&buf[left], &buf[right]);
    left++;
    right--;
  }
}

void showBit(int val)
{
  char buf[32];
  int i = 0;
  int pos;
  int count = 0;
  for(i = 0; i < 32; ++i)
  {
    pos = 1 << i;
    if((val & pos) == 0)
    {
      buf[i] = '0';
    }
    else
    {
      ++count;
      buf[i] = '1';
    }
  }

  resever(buf, 32);

  for(i = 0; i < 32; ++i)
  {
    printf("%c", buf[i]);
  }
  printf("\n");
  printf("count: %d\n", count);
}



int main(int argc, char *argv[])
{
  int val;
  val = atoi(argv[1]);

  showBit(val);
  return 0;
}

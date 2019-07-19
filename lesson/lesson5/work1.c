/*************************************************************************
*File Name: work1.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 09:04:02 PM CST
 ************************************************************************/
//猜数字小游戏
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int val;
  int num;
  srand(time(NULL));
  val = rand() % 100;
  printf("%d", val);
  printf("guess the val:");
  scanf("%d", &num);

  while(num != val)
  {
    setbuf(stdin, NULL);
    if(num > val)
    {
      printf("too big ...\n");
    }
    else
    {
      printf("too small ...\n");
    }
    printf("guess the val:");
    scanf("%d", &num);
  }

  printf("right ...\n");
  return 0;
}

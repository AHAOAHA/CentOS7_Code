/*************************************************************************
*File Name: work2.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 25 Dec 2018 12:21:54 PM CST
 ************************************************************************/
//在整型有序数组中查找固定值
#include <stdio.h>

int main()
{
  int arr[5] = {1,2,3,4,5};
  int val;
  int i = 0;
  printf("val:");
  scanf("%d", &val);
  setbuf(stdin, NULL);

  for(i = 0; i < (int)(sizeof(arr)/sizeof(arr[0])); ++i)
  {
    if(arr[i] == val)
    {
      printf("%d ...\n", i);
      return 0;
    }
  }

  printf("no ...\n");
  return 0;
}

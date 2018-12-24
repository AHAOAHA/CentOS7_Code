/*************************************************************************
*File Name: work4.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 04:10:49 PM CST
 ************************************************************************/
//将3个数字按从小到大输出
//将输入的数字按从小到大排序输出
#include <stdio.h>
#include <malloc.h>
void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(int *arr, int size)
{
  int i;
  int j;
  for(i = 0; i < size - 1; ++i)
  {
    for(j = 0; j < size - i - 1; ++j)
    {
      if(arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }

  }
}
int main()
{
  int *arr;
  int size;
  int i;
  printf("size = ");
  scanf("%d", &size);
  arr = (int*)malloc(size * sizeof(int));

  for(i = 0; i < size; ++i)
  {
    scanf("%d", arr + i);
  }

  sort(arr, size);

  printf("小--->大:");

  for(i= 0; i < size; ++i)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}

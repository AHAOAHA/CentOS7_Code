/*************************************************************************
*File Name: work4.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月14日 星期一 11时37分35秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>

void Init(void* arr, size_t size)
{
  memset(arr, 0, size);
}

void Empty(void* arr, size_t size)
{
  Init(arr,size);
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void reverse(int* arr, size_t size)
{
  int left = 0;
  int right = size - 1;

  while(left < right)
  {
    swap(&arr[left], &arr[right]);
    left++;
    right--;
  }
}

int main()
{
  return 0;
}

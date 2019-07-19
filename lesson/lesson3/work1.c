/*************************************************************************
*File Name: work1.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 04:30:45 PM CST
 ************************************************************************/
//交换数组A和数组B的内容(数组大小相同)
#include <stdio.h>

#define SIZE 5

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swapArr(int arr1[], int arr2[], int size)
{
  int i;
  for(i = 0; i < size; ++i)
  {
    swap(&arr1[i], &arr2[i]);
  }
}


int main()
{
  int i;
  int arr1[SIZE] = {1, 1, 1, 1};
  int arr2[SIZE] = {0, 1};
  printf("arr1:");
  for(i = 0; i < SIZE; ++i)
  {
    printf("%d ", arr1[i]);
  }
  printf("\n");
  printf("arr2:");
  for(i = 0; i < SIZE; ++i)
  {
    printf("%d ", arr2[i]);
  }
  printf("\n");

  swapArr(arr1, arr2, SIZE);

  printf("arr1:");
  for(i = 0; i < SIZE; ++i)
  {
    printf("%d ", arr1[i]);
  }
  printf("\n");
  printf("arr2:");
  for(i = 0; i < SIZE; ++i)
  {
    printf("%d ", arr2[i]);
  }
  printf("\n");
  return 0;
}

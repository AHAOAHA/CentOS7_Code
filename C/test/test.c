#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int (*func)(int, int);

int add(int x, int y)
{
  return x+y;
}
int main()
{
  int ret = func(1, 2);
  printf("%d\n", ret);
  return 0;
}

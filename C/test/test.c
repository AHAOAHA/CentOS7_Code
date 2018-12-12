#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int main()
{
  close(1);
  while(1);
  return 0;
}

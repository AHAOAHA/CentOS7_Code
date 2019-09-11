/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Sun Dec  9 14:39:43 2018
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

#define MAXSIZE 5



int arr[MAXSIZE];
void* Produce_start(void* arg)
{
  for(size_t i = 0;; ++i)
  {

  }
  return arg;
}

void* Consume_start(void* arg)
{
  for(;;)
  {}
  return arg;
}

void Produce()
{
  pthread_t id;
  pthread_create(&id,nullptr, Produce_start,nullptr);
  pthread_detach(id);
}

void Consume()
{
  pthread_t id;
  pthread_create(&id,nullptr, Consume_start,nullptr);
  pthread_detach(id);
}

int main()
{
  srand(time(NULL));
  Produce();
  Consume();
  while(1);
  return 0;
}

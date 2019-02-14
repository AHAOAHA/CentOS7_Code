#include<typeinfo>
#include<string>
#include<iostream>
#include<map>
#include<unistd.h>
using namespace std;

struct A
{
  short a;
  long int b;
  char c;
};

int main()
{
  printf("%d\n", (int)sizeof(A));
  return 0;
}

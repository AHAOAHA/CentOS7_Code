#include<typeinfo>
#include<string>
#include<iostream>
#include<map>
#include<unistd.h>
using namespace std;

static int sum = 10;
int main()
{
  while(1)
  {
    cout << sum <<endl;
    sleep(1);
  }
  return 0;
}

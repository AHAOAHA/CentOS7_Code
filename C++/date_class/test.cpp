#include"date.h"
#include<iostream>
int main()
{
  Date d1(2018,10,21);
  Date d2(1998,07,21);
  Date d3(d1);
  d3.print();
  std::cout<<std::endl;
  d3 += -10000;
  d3.print();
  std::cout<<std::endl;
  printf("%d\n", d2 - d1);
  return 0;
}
#include"date.h"
#include<iostream>
int main()
{
  Date d1(2018,10,21);
  Date d2(1998,07,21);
  Date d3(d1);
  cout<<d3.sort_in_year()<<endl;
  std::cout<<d1<<std::endl;
  d3 += -10000;
  std::cout<<d3<<std::endl; 
  printf("%d\n", d2 - d1);
  return 0;
}

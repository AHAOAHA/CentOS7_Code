#include"date_class.h"
#include<iostream>
int main()
{
  Date d1;
  Date d2(1998,07,21);
  Date d3(d1);
  d3.print();
  std::cout<<std::endl;
  d3 = d3 + 3;
  d3.print();
  std::cout<<std::endl;
  d3 = d3 + 30;
  d3.print();
  std::cout<<std::endl;
  return 0;
}

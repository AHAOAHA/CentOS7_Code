/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月21日 星期一 19时38分09秒
 ************************************************************************/
#include "unique_ptr.hpp"

int main()
{
  int *p = new int(1);
  Unique_Ptr<int> sp(p);
  return 0;
}

/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月17日 星期四 22时16分53秒
 ************************************************************************/

#include "auto_ptr.hpp"

struct test{
  int a;
  int b;
};
int main()
{
  test* ptr = (test*)malloc(sizeof(test));
  Auto_Ptr<test, MallocDeleter<test> >  auto_ptr(ptr);
  auto_ptr->a = 1;
  return 0;
}

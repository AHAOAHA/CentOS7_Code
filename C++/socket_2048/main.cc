/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月25日 星期五 09时03分04秒
 ************************************************************************/
#include "service.hpp"

int main()
{
  Sock service;
  service.SockInit(8080);
  return 0;
}

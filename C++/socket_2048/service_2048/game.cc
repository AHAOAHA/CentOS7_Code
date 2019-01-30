/*************************************************************************
*File Name: game.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月30日 星期三 15时24分55秒
 ************************************************************************/
#include "game.h"

void SuccessConnect(Task* pt)
{
  char buf[64] = "connect success!";
  pt->Send(buf, strlen(buf));
}


/*************************************************************************
*File Name: select.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 19 Mar 2019 04:44:07 PM CST
 ************************************************************************/
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
using std::endl;
using std::cout;
using std::cerr;

bool SetNoBlock(int fd) {
  int fl = fcntl(fd, F_GETFL);
  if(fl < 0) {
    cerr << "F_GETFL error" << endl;
    return false;
  }

  int ret = fcntl(fd, F_SETFL, fl | O_NONBLOCK);
  if(ret < 0) {
    cerr << "F_SETFL error" << endl;
    return false;
  }
  return true;
}

int main()
{
  SetNoBlock(0);
  ssize_t ret = -1;
  while(ret < 0) {
    char buf[1024] = {0};
    size_t ret = read(0, buf, sizeof(buf));
    cout << "reading ..." << endl;
    if(ret > 0) {
      buf[ret] = 0;
      cout << buf << endl;
      sleep(5);
    }
    else
      sleep(1);
  }

  return 0;
}

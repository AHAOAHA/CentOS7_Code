/*************************************************************************
*File Name: service.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月07日 星期一 10时40分13秒
 ************************************************************************/
#include "TcpService.hpp"
#include <unordered_map>

#define SERVICEPORT 7890

void Handler(std::string& req, std::string& resp)
{
  for(auto it = dict.begin(); it != dict.end(); ++it)
  {
    if(it->first == req)
    {
      resp = it->second;
      return;
    }
  }
  resp = "null";
}


int main(int argc, char* argv[])
{
  //if(argc < 2)
  //{
  //  Usage();
  //  exit(EXIT_FAILURE);
  //}
  Sock service;
  service.InitSock(SERVICEPORT);
  service.Run(Handler);
  return 0;
}


/*************************************************************************
*File Name: service.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月07日 星期一 10时40分13秒
 ************************************************************************/
#include "TcpService.hpp"
#include <unordered_map>

std::unordered_map<std::string, std::string> dict;

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


//创建服务器

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    Usage();
    exit(EXIT_FAILURE);
  }
  dict.insert(std::make_pair("hello", "你好"));
  dict.insert(std::make_pair("zhanghao", "张昊"));
  dict.insert(std::make_pair("ahao", "阿昊"));
  dict.insert(std::make_pair("school", "学校"));
  dict.insert(std::make_pair("home", "家"));
  dict.insert(std::make_pair("hehe", "呵呵"));
  Sock service;

  service.InitSock(atoi(argv[1]));
  service.Run(Handler);
  return 0;
}


/*************************************************************************
*File Name: UdpService.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月05日 星期六 13时04分45秒
 ************************************************************************/
#include <unordered_map>
#include "UdpService.hpp"

std::unordered_map<std::string, std::string> dict;
void Usage()
{
  std::cout << "./service [ip] [port]" << std::endl;
}
void Handler(std::string& req, std::string& resp)
{
  auto it = dict.find(req);
  if(it == dict.end())
  {
    resp = "null";
  }
  resp = it->second;
}

int main(int argc, char* argv[])
{
  if(argc < 3)
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

  Sock service(argv[1], atoi(argv[2]));
  service.ServiceStart(Handler);
  return 0;
}

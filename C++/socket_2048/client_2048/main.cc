/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月29日 星期二 21时18分35秒
 ************************************************************************/
#include "client.hpp"

void Usage()
{
  std::cout << "./client [ip] [port]" << std::endl;
}

int array[ROW][COL] = {'\0'};
int Flag_Seed = 1;
int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    Usage();
    exit(EXIT_FAILURE);
  }
  CSock client;

  int ret = client.Connect(argv[1], atoi(argv[2]));
  if(ret < 0)
  {
    std::cerr << "connect fail!" << std::endl;
    exit(EXIT_FAILURE);
  }

  printf("\033[2J");
  char buf[64] = {'\0'};
  //接受连接成功的消息
  client.Recv(buf, sizeof(buf)-1);
  std::cout << buf << std::endl;

  //游戏开始页面
  

  char ch;
  while(!IsDown(array))
  {
    //接收二维数组
    client.Recv(array, ROW*COL*sizeof(int));


    PrintMap(array);

    system("stty raw");
	  ch = getchar();
    system("stty -raw");


    //发送方向字符
    client.Send(&ch, 1);


    //检测退出字符q
    if('q' == ch)
      break;
  
  }

  printf("\033[?25J");

  return 0;
}


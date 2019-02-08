/*************************************************************************
*File Name: Task.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年02月08日 星期五 21时20分09秒
 ************************************************************************/
#pragma once
#include <iostream>
#include "2048.h"

class Task
{
  public:
    void Run()
    {
      std::cout << "get a clientfd "<< _clientfd << std::endl;
  
      //todo游戏主体
      char ch;
      int ret;
      int Flag_Seed = 1;
      int array[ROW][COL] = {0};
      while(!IsDown(array))
      {
        //播种
        if(1 == Flag_Seed)
        {
          Seed(array);
          Flag_Seed = 0;
        }

        PrintArr(array);

        //将游戏地图通过sock传递给客户端
        Send(array, ROW*COL*sizeof(int));

        //接受客户端穿回来的数据
        Recv(&ch, 1);

        ret = MoveMap(array, ch, Flag_Seed);
        if(1 == ret)
          break;
      }

      close(_clientfd);
    }

    Task(int clientfd):_clientfd(clientfd)
    {}
    ~Task()
    {
    }

    //发送信息
    ssize_t Send(void* buf, size_t size)
    {
      return send(_clientfd, buf, size, 0);
    }

    //接受消息
    ssize_t Recv(void* buf, size_t size)
    {
      return recv(_clientfd, buf, size, 0);
    }

    int GetClientfd()
    {
      return _clientfd;
    }

  private:
    int _clientfd;
};

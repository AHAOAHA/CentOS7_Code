#pragma once 
#define nullptr 0
template<class T>
class PList
{
  public:
  PList()//构造函数
    :_pHead(nullptr)
  {}
  push_back(DataType data)
  {
    if()
  }
  
  ~PList()//析构函数
  {}
  private:
    typedef T DataType;
    typedef struct Node
    {
      Node* _pNext;//指向下一个节点
      DataType _data;//结点数据
    }Node;
    Node* _pHead;//头节点
};

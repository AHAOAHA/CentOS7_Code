/*************************************************************************
*File Name: auto_ptr.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月17日 星期四 14时13分46秒
 ************************************************************************/
//auto_ptr,模拟实现最简单的智能指针
#pragma once
#include <iostream>
#include <malloc.h>
//定制删除器

//free删除器
template<class T>
struct MallocDeleter
{
  void operator()(T *ptr)
  {
    std::cout << "MallocDeleter" << std::endl;
    free(ptr);
  }
};

//delete删除器
template<class T>
struct NewDeleter
{
  void operator()(T* ptr)
  {
    std::cout << "NewDeleter" << std::endl;
    delete ptr;
  }
};

//delete[]删除器
template<class T>
struct ArrayDeleter
{
  void operator()(T* ptr)
  {
    std::cout << "ArrayDeleter" << std::endl;
    delete[] ptr;
  }
};

template<class T,  class Deleter = NewDeleter<T> >
class Auto_Ptr
{
  public:
    Auto_Ptr(T *ptr):_ptr(ptr)
    {}

    //拷贝构造函数，auto_ptr的重大缺陷
    Auto_Ptr(Auto_Ptr& ptr):_ptr(ptr)
    {
      ptr._ptr = nullptr;
    }

    //像指针一样使用
    T& operator*()
    {
      return *_ptr;
    }

    T* operator->()
    {
      return _ptr;
    }

    //
    ~Auto_Ptr()
    {
      std::cout << "Deleter: ";
      Deleter()(_ptr);
    }
  private:
    T* _ptr;
};

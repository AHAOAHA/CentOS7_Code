/*************************************************************************
*File Name: unique_ptr.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月21日 星期一 19时37分50秒
 ************************************************************************/
#pragma once
#include <iostream>

template<class T>
struct NewDeleter
{
  void operator()(T* ptr)
  {
    std::cout << "NewDeleter()" << std::endl;
    delete ptr;
  }
};

template<class T>
struct MallocDeleter
{
  void operator()(T* ptr)
  {
    std::cout << "MallocDeleter()" << std::endl;
    free(ptr);
  }
};

template<class T>
struct ArrayDeleter
{
  void operator()(T* ptr)
  {
    std::cout << "ArrayDeleter()" << std::endl;
    delete[] ptr;
  }
};

template<class T, class Deleter = NewDeleter<T> >
class Unique_Ptr
{
  public:
    Unique_Ptr(T* ptr):_ptr(ptr)
    {}

    T& operator*()
    {
      return *_ptr;
    }

    T*& operator->()
    {
      return _ptr;
    }

    //析构函数需要定制删除器
    ~Unique_Ptr()
    {
      Deleter()(_ptr);
    }

  private:
    //禁止拷贝构造和赋值
    Unique_Ptr(Unique_Ptr& sp):_ptr(sp._ptr)
    {}

    Unique_Ptr& operator=(Unique_Ptr& sp)
    {
      sp;
    }

  private:
    T* _ptr;
};

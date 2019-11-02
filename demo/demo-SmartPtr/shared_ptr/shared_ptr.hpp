/*************************************************************************
*File Name: shared_ptr.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月21日 星期一 22时18分06秒
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
class Shared_Ptr
{
  public:
    Shared_Ptr(T* ptr):_ptr(ptr), _pCount(new int(0))
    {}

    Shared_Ptr(Shared_Ptr& sp):_ptr(sp._ptr), _pCount(sp._pCount)
    {
      *_pCount = *_pCount + 1;
    }

    Shared_Ptr& operator=(Shared_Ptr& sp)
    {
      _ptr = sp._ptr;
      _pCount = sp._pCount;

      *_pCount = *_pCount + 1;
    }

    T& operator*()
    {
      return *_ptr;
    }

    T*& operator->()
    {
      return _ptr;
    }

    ~Shared_Ptr()
    {
      if((*_pCount) > 1)
      {
        (*_pCount) -= 1;
      }

      else
      {
        Deleter()(_ptr);
        delete _pCount;
      }
    }
  private:
    T *_ptr;
    //引用计数
    int* _pCount;
};

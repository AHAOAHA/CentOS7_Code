/*
 * 一个只可以在栈上创建对象的类
 */
#ifndef _STACK_OBJ_H_
#define _STACK_OBJ_H_



class stack_obj
{
  public:
    static stack_obj GetObj()//设置创建对象的接口，并将该接口设置为静态函数成员，这样就可以通过作用于直接在类外创建对象
    {
      stack_obj obj;
      return obj;
    }
  private:
    //构造函数私有化
    stack_obj()
    {}
    stack_obj(const stack_obj& obj)
    {}

    //数据成员
    int _i;

};



#endif

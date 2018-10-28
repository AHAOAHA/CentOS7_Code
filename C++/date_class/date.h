/*
 * 遇到的问题：
 *           1.重定向<<时，返回值为引用类型，则接受参数的值也应该为引用类型！
 *           2.如果类的友元函数要访问类的私有函数成员，则该成员必须声明为static，声明之后可以通过类名在友元函数内访问
 */
#ifndef _DATE_H_
#define _DATE_H_
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Date
{
  public:
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
    Date(int year = 2018,int month = 10, int day = 1);
    Date(const Date& d);

    bool operator==(const Date& d)const;
    bool operator!=(const Date& d)const;
    bool operator<=(const Date& d)const;
    bool operator>=(const Date& d)const;
    bool operator<(const Date& d)const;
    bool operator>(const Date& d)const;
    Date operator+(const int count)const;
    Date operator-(const int count)const;
    Date& operator+=(const int count);
    Date& operator-=(const int count);
    int operator-(const Date& d)const;
    int sort_in_year()const;

    void print()const;
  private:
    /*
     * 经常调用get_month_day函数，所以get_month_day函数应该被声明为内联函数
     */ 
    inline static int get_month_day(int year, int month);
    int _year;
    int _month;
    int _day;
};

#endif

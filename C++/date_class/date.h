#ifndef _DATE_H_
#define _DATE_H_
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
class Date
{
  public:
    Date(int year = 2018,int month = 10, int day = 1);
    Date(Date& d);

    bool operator==(const Date& d)const;
    bool operator!=(const Date& d)const;
    bool operator<=(const Date& d)const;
    bool operator>=(const Date& d)const;
    bool operator<(const Date& d)const;
    bool operator>(const Date& d)const;
    Date operator+(const int count);
    Date operator-(const int count);
    Date& operator+=(const int count);
    Date& operator-=(const int count);
    int operator-(const Date& d);

    void print()const;
  private:
    /*
     * 经常调用get_month_day函数，所以get_month_day函数应该被声明为内联函数
     */ 
    inline int get_month_day(int year, int month);
    int _year;
    int _month;
    int _day;
};
#endif

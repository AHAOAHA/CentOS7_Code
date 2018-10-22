#pragma once 
#include<iostream>
#include<stdlib.h>
class Date
{
  public:
    Date(int year = 2018,int month = 10, int day = 1)
    {
      if(month > 12 || month <= 0 || day <= 0 || day > get_month_day(year, month))
      {
        std::cout << "时间格式错误!" << std::endl;
        exit(-1);
      }
      _year = year;
      _month = month;
      _day = day;
    }

    Date(Date& d)
    {
      _year = d._year;
      _month = d._month;
      _day = d._day;
    }

    bool operator==(const Date& d)const
    {
      return _year == d._year 
          && _month == d._month
          && _day == d._day;
    }
    bool operator!=(const Date& d)const
    {
      return !((*this) == d);
    }
    bool operator<=(const Date& d)const
    {
      return !((*this) > d);
    }
    bool operator>=(const Date& d)const
    {
      return !((*this) < d);
    }
    bool operator<(const Date& d)const
    {
      return !((*this) == d || (*this) > d);
    }
    bool operator>(const Date& d)const
    {
      if(_year > d._year)
        return true;
      else if(_year == d._year)
      {
        if(_month > d._month)
          return true;
        else if(_month == d._month)
        {
          if(_day > d._day)
            return true;
        }
      }
      return false;
    }
    Date operator+(const int count)
    {
      Date temp(*this);
      if(count < 0)
      {
        temp = temp - (-count);
        return temp;
      }
      temp._day += count;
      while(temp._day > get_month_day(temp._year,temp._month))
      {
        if(temp._month<12)
        {
          temp._month += 1;
        }
        else
        {
          temp._year += 1;
          temp._month = 1;
        }
        temp._day -= get_month_day(temp._year,temp._month);
      }
      return temp;
    }

    Date operator-(const int count)
    {
      Date temp(*this);
      if(count < 0)
      {
        temp = temp + (-count);
        return temp;
      }
      temp._day -= count;
      while(temp._day <= 0)
      {
        if((temp._month - 1) > 0)
        {
          temp._month -= 1;
        }
        else
        {
          temp._year -= 1;
          temp._month = 12;
        }
        temp._day += get_month_day(temp._year,temp._month);
      }
      return temp;
    }
    Date& operator+=(const int count)
    {
      (*this) = (*this) + count;
      return (*this);
    }
    Date& operator-=(const int count)
    {
      (*this) = (*this) - count;
      return (*this);
    }
    void print()
    {
      std::cout << _year << "/" << _month << "/" << _day;
    }
  private:
    int get_month_day(int year, int month)
    {
      if(month <= 0 || month > 12)
      {
        exit(-1);
      }
      const static unsigned int array[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
      if(((year % 4 == 0 && year % 100 != 0) ||
          (year % 400 == 0)) && 
          (month == 2))
      {
        return 29;
      }
      return array[month];
    }
    int _year;
    int _month;
    int _day;
};

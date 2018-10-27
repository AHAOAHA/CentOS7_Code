#include"date.h"

/*
 * 构造函数在类外定义时，缺省值不需要给出
 */
Date::Date(int year,int month, int day)
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

Date::Date(Date& d)
{
  _year = d._year;
  _month = d._month;
  _day = d._day;
}

bool Date::operator==(const Date& d)const
{
  return _year == d._year 
      && _month == d._month
      && _day == d._day;
}
bool Date::operator!=(const Date& d)const
{
  return !((*this) == d);
}
bool Date::operator<=(const Date& d)const
{
 return !((*this) > d);
}
bool Date::operator>=(const Date& d)const
{
  return !((*this) < d);
}
bool Date::operator<(const Date& d)const
{
  return !((*this) == d || (*this) > d);
}
bool Date::operator>(const Date& d)const
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
Date Date::operator+(const int count)
{
  Date temp(*this);
  temp += count;
  return temp;
}

Date Date::operator-(const int count)
{
  Date temp(*this);
  temp -= count;
  return temp;
}

/*
 * 实现+=/-=时，不产生临时变量
 */

Date& Date::operator+=(const int count)
{
  if(count < 0)
  {
    return (*this) -= (-count);
  }
  _day += count;
  while(_day > get_month_day(_year,_month))
  {
    if(_month<12)
    {
      _month += 1;
    }
    else
    {
      _year += 1;
      _month = 1;
    }
    _day -= get_month_day(_year,_month);
  }
  return (*this);
}


Date& Date::operator-=(const int count)
{
  if(count < 0)
  {
    return (*this) += (-count);
  }
  _day -= count;
  while(_day <= 0)
  {
    if((_month - 1) > 0)
    {
      _month -= 1;
    }
    else
    {
      _year -= 1;
      _month = 12;
    }
    _day += get_month_day(_year,_month);
  }
  return (*this);
}
/*
 * 日期减日期
 */
int Date::operator-(const Date& d)
{
  Date min;
  Date max;
  int count = 0;
  int flag;
  if((*this) >= d)
  {
    max = *this;
    min = d;
    flag = 1;
  }
  else
  {
    max = d;
    min = *this;
    flag = -1;
  }

  while(max != min)
  {
    min += 1;
    count += 1;
  }
  return count*flag;
}

void Date::print()const
{
   std::cout << _year << "/" << _month << "/" << _day;
}
int Date::get_month_day(int year, int month)
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

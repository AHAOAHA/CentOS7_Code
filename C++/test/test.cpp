#include<typeinfo>
#include<string>
#include<iostream>
#include<map>
using namespace std;
class test
{
  private:
    int a = 1;
};
int main()
{
  map<string, string> a;
  map<string, string>::iterator it= a.begin();
  auto b = it;
  cout<<typeid(b).name()<<endl;
  cout<<typeid(it).name()<<endl;
  return 0;
}

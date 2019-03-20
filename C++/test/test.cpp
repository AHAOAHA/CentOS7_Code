#include <iostream>
using std::cout;
using std::endl;

struct Test{
  int b;
  char a;
};
int main()
{
  Test t;
  t.a = 'a';
  cout << sizeof(t) << endl;
  return 0;
}

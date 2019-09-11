#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

using std::cout;
using std::endl;
/*

void IToStr(std::string& str, int fd) {
  std::string tmp;
  while(fd > 0) {
    int num = fd % 10;
    tmp += (char)(num + '0');
    fd /= 10;
  }
  int left = 0;
  int right = tmp.size() - 1;
  while(left < right)
  {
    std::swap(tmp[left], tmp[right]);
    left++;
    right--;
  }

  str += tmp;
}

int main()
{
  int fd = 3;
  int count = 3;
  while(1) {
    std::string filename("./tmp/test.txt");
    IToStr(filename, count);
    fd = open(filename.c_str(), O_RDWR|O_CREAT, 0644);
    if(fd < 0) {
      break;
    }
    cout << filename << " is open ..." << endl;
    count++;
    sleep(1);
  }
}

*/

typedef void (*pF)();

class base {
  public:
    virtual void f() {
      cout << "base::hello world!" << endl;
    }
};

class dec : public base {
  public:
    virtual void f() {
      cout << "dec::hello world!" << endl;
    }
};

void TestString() {
  std::string s;

  s = "aaa";

  s.resize(100);

  cout << s << endl;

  write(1, s.c_str(), s.size());

}

int main() {
  /*
  base b;
  dec d;
  pF* pb = (pF*)&b;
  pF* pd = (pF*)&d;

  pF = (pF)(*pb);

  b.f();
  */
  TestString();

  
  return 0;
}
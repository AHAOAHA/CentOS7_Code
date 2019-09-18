/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: main.cpp
 * Author: ahaoozhang
 * Date: 2019-09-15 23:09:39 (星期日)
 * Describe: 
 *************************************************/
#include <iostream>

using namespace std;

class Test {
    public:
        inline void Echo() {
            cout << "hell oworld!" << endl;
        }

        static void EchoAddr() {
            cout << &Test::Echo << endl;
        }
};

int main() {
    Test t;
    Test::EchoAddr();
    //cout << (int*)Test::Echo << endl;
    return 0;
}

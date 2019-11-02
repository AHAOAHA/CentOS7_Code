/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: Lambda.cpp
 * Author: ahaoozhang
 * Date: 2019-09-26 13:04:00 (Thursday)
 * Describe: 
 *************************************************/
#include <iostream>
#include <typeinfo>
using namespace std;

typedef int (*pF)();

int main() {
    int ret = 0;
    int a  = 3;
    int* i = &a;
    auto p = [&]() -> int { cout << a << endl; return 1;};
    ret = p();
    cout << typeid(p).name() << endl;
    cout << typeid(i).name() << endl;

    return 0;
}

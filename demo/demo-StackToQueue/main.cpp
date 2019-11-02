/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: main.cpp
 * Author: ahaoozhang
 * Date: 2019-09-11 17:33:55 (星期三)
 * Describe: 
 *************************************************/
#include "StackToQueue.hpp"
#include <iostream>

using std::cout;
using std::endl;

void TestqStack() {
    AHAOAHA::qStack<int> qst;

    qst.push(1);
    qst.push(2);
    qst.push(3);

    while(!qst.empty()) {
        int tmp = qst.pop();

        cout << tmp << endl;
    }
}

int main() {
    TestqStack();
    return 0;
}

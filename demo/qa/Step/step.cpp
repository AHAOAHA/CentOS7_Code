/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: step.cpp
 * Author: ahaoozhang
 * Date: 2019-10-13 20:42:33 (Sunday)
 * Describe: 台阶问题，一次只能走一个或者两个台阶，N个台阶一共有几种走法 
 *************************************************/


#include <iostream>

using namespace std;


int Step(int n) {
    if (n < 2) {
        return 1;
    }

    return Step(n - 1) + Step(n - 2);
}

int main() {
    int n = 0;
    while(cin >> n)
        cout << Step(n) << endl;
    return 0;
}

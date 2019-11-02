/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: findx.cpp
 * Author: ahaoozhang
 * Date: 2019-10-13 21:01:15 (Sunday)
 * Describe: 
 *************************************************/
#include <iostream>

using namespace std;

int FindX(int num, int x) {
    int count = 0;
    while(num) {
        int last = num % 10;
        num = num / 10;
        if(last == x) {
            count++;
        }
    }

    return count;
}

int main() {
    int begin, end, x;
    while(cin >> begin >> end >> x) {
        int num = begin;
        int count = 0;
        while(num <= end) {
            count += FindX(num, x);
            num++;
        }

        cout << count << endl;
    }
    return 0;
}

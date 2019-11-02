/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: BinaryConversion.cpp
 * Author: ahaoozhang
 * Date: 2019-09-10 13:15:07 (星期二)
 * Describe: 十进制到任意进制转换
 *************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    //int base_in;
    int conversion_in;
    //cout << "BinaryConversion ..." << endl << "base_in: ";
    //cin >> base_in;
    cout << "conversion_in: ";
    cin >> conversion_in;

    int num;
    while(1) {
        cout << "input num: ";
        cin >> num;

        string s;
        while(num / conversion_in != 0) {
            int tmp = num % conversion_in;
            num = num / conversion_in;

            s += ('0' + tmp);
        }

        s += ('0' + num);

        reverse(s.begin(), s.end());

        cout << "conversion_num: " << s << endl;
    }
    
    return 0;
}
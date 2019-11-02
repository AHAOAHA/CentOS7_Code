/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: main.cc
 * Author: ahaoozhang
 * Date: 2019-08-04 00:25:34 (星期日)
 * Describe: 网易笔试题
 *************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::cin;

int main() {
    uint64_t n = 0;
    int64_t q = 0;

    while(cin >> n) {
        cin >> q;
        //val ok
        // n in
        std::vector<int64_t> v_val;
        std::vector<int64_t> v_find;
        for(uint64_t i = 0; i < n; i++) {
            int64_t tmp = 0;
            cin >> tmp;
            v_val.push_back(tmp);
        }

        for (int64_t line = 0; line < q; line++) {
            int64_t num = 0;
            cin >> num;
            v_find.push_back(num);
        }

        for(auto& find_val:v_find) {
            uint64_t count = 0;
            for (auto &e : v_val) {
                if (e >= find_val) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}


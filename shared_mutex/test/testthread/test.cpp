/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: test.cpp
 * Author: ahaoozhang
 * Date: 2019-07-28 20:01:14 (星期日)
 * Describe: 
 *************************************************/
#include <thread>

void f1() {
    printf("hello");
}
void f2(int *i) {
    while(*i != 100) {
        printf("i = %d\n", *i++);
    }
}

int main() {
    std::thread t1(f1);
    int i = 0;
    std::thread t2(f2, &i);
    t1.join();
    t2.join();
    return 0;
}

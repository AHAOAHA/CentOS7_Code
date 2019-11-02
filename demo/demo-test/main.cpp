/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: main.cpp
 * Author: ahaoozhang
 * Date: 2019-09-15 23:09:39 (星期日)
 * Describe: 
 *************************************************/
#include <iostream>
#include <semaphore.h>

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

void TestA() {
    cout << "hello world!" << endl;
}

int main() {
    Test t;
    //Test::EchoAddr();
    //cout << (int*)Test::Echo << endl;
    //auto p = TestA;
    //if(p == *TestA) {
    //    cout << "1" << endl;
    //}
    //if(p == &TestA) {
    //    cout << "2" << endl;
    //}
    //if(TestA == &TestA) {
    //    cout << "3" << endl;
    //}
    sem_t sem;
    sem_init(&sem, 1, 1);
    while(1);
    return 0;
}

/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: test.cpp
 * Author: ahaoozhang
 * Date: 2019-08-04 20:21:22 (星期日)
 * Describe: 
 *************************************************/
#include "rw_mutex.h"
#include <unistd.h>
#include <pthread.h>


int num = 0;
AHAOAHA::rw_mutex rw_mtx;


void read() {
    rw_mtx.r_lock();
    printf("num = %d\n", num);
    rw_mtx.r_unlock();
}

void write() {
    rw_mtx.w_lock();
    sleep(1);
    num++;
    rw_mtx.w_unlock();
}

void* read_handle(void* arg) {
    while(1) {
        read();
    }
    return arg;
}

void* write_handle(void* arg) {
    while(1) {
        write();
    }
    return arg;
}

int main() {
    pthread_t p1;
    pthread_t p2;
    
    pthread_create(&p2, NULL, write_handle, NULL);
    sleep(1);
    pthread_create(&p1, NULL, read_handle, NULL);

    while(1);   //主线程不退出
    return 0;
}

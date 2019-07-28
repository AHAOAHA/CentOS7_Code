/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: test.cpp
 * Author: ahaoozhang
 * Date: 2019-07-28 19:33:35 (星期日)
 * Describe: 
 *************************************************/
#include <pthread.h>
#include "rw_mutex.h"
#include <iostream>
#include <unistd.h>
int i = 0;

void* read(void* arg) {
    AHAOAHA::rw_mutex* rw_mtx = (AHAOAHA::rw_mutex*)arg;
    while (1) {
        sleep(3);
        rw_mtx->r_lock();
        std::cout << "i = " << i << std::endl;
        rw_mtx->r_unlock();
    }
    return NULL;
}

void* write(void* arg) {
    AHAOAHA::rw_mutex* rw_mtx = (AHAOAHA::rw_mutex*)arg;
    while(1) {
        sleep(1);
        rw_mtx->w_lock();
        std::cout << "now r: " << rw_mtx->get_r_count() << std::endl;
        i = i++;
        rw_mtx->w_unlock();
    }
    return NULL;
}

int main() {
    AHAOAHA::rw_mutex rw_mtx;
    pthread_t t1,t2;
    pthread_create(&t1, NULL, read, (void*)&rw_mtx);
    pthread_create(&t2, NULL, write, (void*)&rw_mtx);
    pthread_detach(t1);
    pthread_detach(t2);
    while(1);
    return 0;
}

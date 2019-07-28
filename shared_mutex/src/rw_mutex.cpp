/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: rw_mutex.cpp
 * Author: ahaoozhang
 * Date: 2019-07-28 17:34:32 (星期日)
 * Describe: 
 *************************************************/
#include "rw_mutex.h"

bool AHAOAHA::rw_mutex::r_lock() {
    int i = IS_READ;
    while (!_status.compare_exchange_strong(i, IS_READ)) {
        //当前资源正在写入
        printf("waiting...");
        usleep(10);
    }

    //原子操作
    _r_count++;
    _status = IS_READ;

    return true;
}

bool AHAOAHA::rw_mutex::r_unlock() {
    _r_count--;
    return true;
}

uint32_t AHAOAHA::rw_mutex::get_r_count() {
    return _r_count;
}

bool AHAOAHA::rw_mutex::w_lock() {
    _status = IS_WRITE; //现将状态改为读状态

    while(_r_count == 0) {
    }

    _mtx.lock();
    return true;
}

bool AHAOAHA::rw_mutex::w_unlock() {
    _mtx.unlock();
    _status = IS_READ;
}

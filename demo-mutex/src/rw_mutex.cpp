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
    bool is_write = false;
    while (!_is_write.compare_exchange_strong(is_write, true)) {
        //当前资源正在写入
        //printf("waiting...\n");
        is_write = false;
    }
    //原子操作
    _r_count++;
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
    _is_write.store(true);
    //等待读者完成 cas
    uint64_t r_count = 0;
    while(!_r_count.compare_exchange_strong(r_count, r_count)) {
        usleep(1);
        r_count = 0;
    } 
    _mtx.lock();
    return true;
}

bool AHAOAHA::rw_mutex::w_unlock() {
    _mtx.unlock();
    _is_write.store(false);
}

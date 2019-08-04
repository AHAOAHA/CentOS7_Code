/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: rw_mutex.h
 * Author: ahaoozhang
 * Date: 2019-07-28 17:34:46 (星期日)
 * Describe: 
 *************************************************/
#ifndef __RW_MUTEX_H__
#define __RW_MUTEX_H__

#include <mutex>
#include <atomic>
#include <unistd.h>

namespace AHAOAHA {
    class rw_mutex{
        public:
            rw_mutex():_r_count(0), _is_write(false) {
                _r_count = 0;
            }
            ~rw_mutex() {}

            bool r_lock();
            bool r_unlock();
            bool w_lock();
            bool w_unlock();
            uint32_t get_r_count();

        private:
            std::mutex _mtx;    //lock
            std::atomic<bool> _is_write;   //
            std::atomic<uint64_t> _r_count; //原子性的计数
    };
}

#endif // rw_mutex

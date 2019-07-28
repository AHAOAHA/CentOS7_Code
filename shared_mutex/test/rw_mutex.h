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

namespace AHAOAHA {
    class rw_mutex {
        enum {
            IS_READ,
            IS_WRITE
        };

        public:
            rw_mutex():_r_count(0), _status(IS_READ) {
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
            std::atomic<int> _status;
            std::atomic<uint64_t> _r_count;
    };
}

#endif // rw_mutex

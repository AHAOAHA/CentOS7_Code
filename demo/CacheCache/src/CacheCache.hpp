/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: CacheCache.h
 * Author: ahaoozhang
 * Date: 2019-07-27 20:30:01 (星期六)
 * Describe: 
 *************************************************/
#ifndef __CACHECACHE_H__
#define __CACHECACHE_H_
#include <unordered_map>

//添加boost库shared_mutex
#include <boost/thread/shared_mutex.hpp>

namespace AHAOAHA {

    template<class Key, class Value>
    class CacheCache {
        public:
            CacheCache():_expr_time(-1), _max_mem(-1)
            {}

            ~CacheCache() {}

            bool Get(const Key& k, Value& v) {
                //获取读写锁状态
                //读锁定
                _RW_Lock.lock_shared();

                //查询是否有key值
                auto got = _cache_map.find(k);
                if (got == _cache_map.end()) {
                    //当前缓存中无相应对象
                    _RW_Lock.unlock_shared();
                    return false;
                }

                v = _cache_map[k];
                _RW_Lock.unlock_shared();
                return true;
                
            }
            bool Put(Key k, Value v) {
                //写锁定
                _RW_Lock.lock();

                auto got = _cache_map.find(k);
                if (got != _cache_map.end()) {
                    _RW_Lock.unlock();
                    return false;
                }

                _cache_map[k] = v;
                _RW_Lock.unlock();
                return true;
            }

            bool SetMaxMem(uint64_t max_mem) {
                _max_mem = max_mem;
            }
            bool SetExprTime(uint64_t expr_time/*second*/) {
                _expr_time = expr_time;
            }

        private:

            std::unordered_map<Key, Value> _cache_map; //缓存
            uint64_t _expr_time;    //过期时间
            uint64_t _max_mem;  //最大队列
    };
}


#endif //cachecache.h

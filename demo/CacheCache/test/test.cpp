/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: test.cpp
 * Author: ahaoozhang
 * Date: 2019-07-28 16:09:16 (星期日)
 * Describe: 
 *************************************************/
#include "CacheCache.h"
#include <iostream>
#include <string>

using namespace AHAOAHA;
using namespace std;

int main() {
    CacheCache<int, string> cache;
    cache.Put(1, "ahaoaoa");
    cache.Put(2, "hahahhaa");

    string tmp;
    cache.Get(2, tmp);
    std::cout << tmp << std::endl;
    return 0;
}

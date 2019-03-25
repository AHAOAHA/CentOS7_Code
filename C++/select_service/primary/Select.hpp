/*************************************************************************
 * File Name: Select.hpp
 * Author: AHAOAHA
 * mail: ahaoaha_@outlook.com
 * Created Time: Mon 25 Mar 2019 08:15:04 PM CST
 ************************************************************************/
#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <vector>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

namespace AHAOAHA {
    void AddFdToVec(std::vector<int>& v, int &max_sock, const int &sock) {
        v.push_back(sock);
        for(const auto& e : v) {
            if(e > max_sock) {
                max_sock = e;
            }
        }
    }

    void SetSet(std::vector<int>& v, fd_set &set) {
        FD_ZERO(&set);
        for(auto e : v) {
            FD_SET(e, &set);
        }
    }

}



#endif

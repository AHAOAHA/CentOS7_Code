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
#include <iostream>

#define FDSETSIZE sizeof(fd_set)*8

using std::cout;
using std::endl;

namespace AHAOAHA {
    bool AddFdToVec(std::vector<int>& v, int &max_sock, const int &sock) {
        if(v.size() == FD_SETSIZE) {
            close(sock);
            return false;
        }
        v.push_back(sock);
        for(const auto& e : v) {
            if(e > max_sock) {
                max_sock = e;
            }
        }
        return true;
    }

    void DelFdInVec(std::vector<int>& v, int &max_sock, const int &pos) {
       v.erase(v.begin()+pos);
       for(const auto& e : v) {
           if(e > max_sock) {
               max_sock = e;
           }
       }
    }

    bool MoveFd(std::vector<int>& v_source, std::vector<int>& v_obj, int &max_sock,const int& pos) {
        int tmp = v_source[pos];    //将源fd保存
        DelFdInVec(v_source, max_sock, pos);
        return AddFdToVec(v_obj, max_sock, tmp);
    }

    void SetSet(std::vector<int>& v, fd_set &set) {
        FD_ZERO(&set);
        for(auto e : v) {
            FD_SET(e, &set);
        }
    }

}



#endif

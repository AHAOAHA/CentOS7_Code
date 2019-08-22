/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: IpToInt.cpp
 * Author: ahaoozhang
 * Date: 2019-08-22 19:52:26 (星期四)
 * Describe: 
 *************************************************/
#include <string>
#include <vector>
#include <iostream>

unsigned int IpToInt(std::string ip) {
    std::vector<unsigned int> ip_int_part;
    int start_pos = 0;
    int count = 3;
    while(1) {
        int pos = ip.find('.', start_pos);
        ip_int_part.push_back(atoi(ip.substr(start_pos, pos).c_str()) << (8 * count--));
        if(pos == std::string::npos) {
            break;
        }
        start_pos = pos + 1;
    }

    std::cout << "part[0]: " << ip_int_part[0]
              << " part[1]: " << ip_int_part[1]
              << " part[2]: " << ip_int_part[2]
              << " part[3]: " << ip_int_part[3]
              << std::endl;

    unsigned int ip_int = 0;
    for (int i = 0; i < ip_int_part.size(); ++i) {
        ip_int = ip_int | ip_int_part[i];
    }
    return ip_int;
}



int main() {
    std::string ip;
    while(std :: cin >> ip) {
        unsigned int ip_int = IpToInt(ip);
        std::cout << "Ip Unsigned Int: " << ip_int << std::endl;
    }
    return 0;
}

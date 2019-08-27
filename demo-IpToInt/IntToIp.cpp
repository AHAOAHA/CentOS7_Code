/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: IntToIp.cpp
 * Author: ahaoozhang
 * Date: 2019-08-23 11:43:22 (星期五)
 * Describe: 
 *************************************************/
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

std::string IntToIp(unsigned int int_ip) {
    std::vector<unsigned int> ip_part;
    char buff[256] = {0};
    size_t count = 0;

    while(count != 4) {
        ip_part.push_back((int_ip >> (count++ * 8)) & 0x000000FF);

    }

    std::cout << "IP_PART_1: " << ip_part[0]
              << " IP_PART_2: " << ip_part[1] 
              << " IP_PART_3: " << ip_part[2] 
              << " IP_PART_4: " << ip_part[3] << std::endl;
    sprintf(buff, "%d.%d.%d.%d", ip_part[3], ip_part[2], ip_part[1], ip_part[0]);
    return buff;
}


int main() {
    unsigned int int_ip;
    while(std::cin >> int_ip) {
        std::string ip = IntToIp(int_ip);
        printf("IntIP: [%u], IP: [%s]\n", int_ip, ip.c_str());
    }
    return 0;
}

/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: log.h
 * Author: ahaoozhang
 * Date: 2019-08-13 16:32:33 (星期二)
 * Describe: 日志
 *************************************************/
#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <unistd.h>
#include <time.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>

namespace AHAOAHA {
    class Logger {
        public:
            Logger():_lfd(-1), _lfn(""), _lph("../log/") {}
            ~Logger() {
                close(_lfd);
            }

            bool Init();
            size_t LogInfo(const char* fmt, ...);
            size_t LogError(const char* fmt, ...);
            size_t LogWarn(const char* fmt, ...);
            size_t LogOutput(const char* fmt, ...);  //返回值为单条日志的长度

        private:
            bool InitTime();
            bool FdIsExpr();
            bool FlushLogFile();


        private:
            int _lfd;  //log fd
            std::string _lfn;   //log file name
            const std::string _lph; //log path
            std::string _lfp;   // path+name
            time_t _tv; //时间戳 用来计算文件更新
    };
}

#endif //log.h

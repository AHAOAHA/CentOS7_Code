/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: log.cpp
 * Author: ahaoozhang
 * Date: 2019-08-13 16:32:40 (星期二)
 * Describe: 
 *************************************************/
#include "logger.h"

namespace AHAOAHA {
    //err log文件命名：xxxx-xx-xx.SsockErr
    bool Logger::Init() {
        SetSecondDayTime(); //设置第二天0点时间戳

        //初始化当天日志文件名
        time_t curr = time(NULL);
        char tmp[255] = {0};
        strftime(tmp, sizeof(tmp), "%Y-%m-%d.SsockErr", localtime(&curr));
        //获取Err文件名
        _lfn = tmp;
        _lfp = _lph + _lfn;

        umask(0);
        //create Log file, only write
        _lff = fopen(_lfp.c_str(), "a");
        if (_lff == nullptr) {
            return false;
        }
        
        return true;
    }

    int Logger::LogInfo(const char* fmt, ...) {
        if(FlushLogFile() == false) {
            return false;
        }

        int ret = 0;
        std::string fmt_str("[INFO]");
        fmt_str += fmt;
        va_list args;
        va_start(args, fmt);
        ret = vfprintf(_lff, fmt_str.c_str(), args);
        va_end(args);
        return ret;
    }

    int Logger::LogError(const char* fmt, ...) {
        if(FlushLogFile() == false) {
            return false;
        }

        int ret = 0;
        std::string fmt_str("[ERROR]");
        fmt_str += fmt;
        va_list args;
        va_start(args, fmt);
        ret = vfprintf(_lff, fmt_str.c_str(), args);
        va_end(args);
        return ret;
    }

    /*
     * Output函数打印一条日志，一定打印在当天的日志文件中
     */
    int Logger::Output(const char* fmt, ...) {
        if(FlushLogFile() == false) {
            return false;
        }

        std::string currtm = GetCurrTime();
        std::string fmt_str;
        fmt_str = '[' + currtm + ']' + ' '+ fmt;

        int ret = 0;
        va_list args;
        va_start(args, fmt);
        ret = vfprintf(_lff, fmt_str.c_str(), args);
        va_end(args);
        return ret;
    }

    //private ===================================================>

    //true 未过期 false 过期
    bool Logger::FdIsExpr() {
        time_t curr = time(NULL);
        return curr < _tv;
    }

    std::string Logger::GetCurrTime() {
        time_t curr = time(NULL);
        char tmp[255] = {0};
        strftime(tmp, sizeof(tmp), "%Y/%m/%d %H:%M:%S", localtime(&curr));
        return std::string(tmp);
    }

    bool Logger::FlushLogFile() {
        if(!FdIsExpr()) {
            //初始化当天日志文件名
            time_t curr = time(NULL);
            char tmp[255] = {0};
            strftime(tmp, sizeof(tmp), "%Y-%m-%d.SsockErr", localtime(&curr));
            //获取Err文件名
            _lfn = tmp;
            _lfp = _lph + _lfn;

            fclose(_lff);

            _lff = fopen(_lfp.c_str(), "a");
            if (_lff == nullptr) {
                return false;
            }

        }
        return true;
    }



    bool Logger::SetSecondDayTime() {
        //设置第二天0点时间戳
        time_t now = time(NULL);
        struct tm* ptoday = localtime(&now);
        time_t seconds;
        ptoday->tm_hour = 0;
        ptoday->tm_min = 0;
        ptoday->tm_sec = 0;
        seconds = 24 * 60 * 60 - difftime(now, mktime(&*ptoday));
        _tv = seconds;
    }
}


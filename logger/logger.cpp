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
        InitTime(); //设置第二天0点时间戳

        //初始化当天日志文件名
        time_t curr = time(NULL);
        char tmp[255] = {0};
        strftime(tmp, sizeof(tmp), "%Y-%m-%d.SsockErr", localtime(&curr));
        //获取Err文件名
        _lfn = tmp;
        _lfp = _lph + _lfn;

        //初始化当天日志文件句柄
        umask(0);
        if(access(_lfp.c_str(), F_OK) < 0) {
            //create log file
            _lfd = open(_lfp.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0660);
            if (_lfd < 0) {
                return false;
            }
        } else {
            _lfd = open(_lfp.c_str(), O_WRONLY | O_APPEND);
            if (_lfd < 0) {
                return false;
            }
        }
        return true;
    }

    size_t Logger::LogInfo(const char* fmt, ...) {
        std::string fmt_str("[INFO]");
        fmt_str += fmt;
        va_list args;
        va_start(args, fmt);
        size_t count = LogOutput(fmt, args);
        va_end(args);
        return count;
    }

    size_t Logger::LogError(const char* fmt, ...) {
        std::string fmt_str("[ERROR]");
        fmt_str += fmt;
        va_list args;
        va_start(args, fmt);
        printf("fmt: %s\n", fmt_str.c_str());
        size_t count = LogOutput(fmt, args);
        va_end(args);
        return count;

    }


    size_t Logger::LogOutput(const char* fmt, ...) {
        std::string buff;

        int tmp = 0;
        va_list arg;    //记录可变参数

        char* p_fmt = nullptr;  //作为fmt 标记

        std::string tmp_str;
        int tmp_num;
        char tmp_ch;
        
        va_start(arg, fmt);
        for(p_fmt = const_cast<char*>(fmt); *(p_fmt) != '\0';) {
            switch(*p_fmt) {
                case '%':
                    p_fmt++;
                    switch (*p_fmt) {
                        case 'c':
                            tmp_ch = va_arg(arg, char);
                            buff += tmp_ch;
                            p_fmt++;
                            break;
                        case 'd':
                            tmp_num = va_arg(arg, int);
                            buff += std::to_string(tmp_num);
                            p_fmt++;
                            break;
                        case 's':
                            tmp_str = va_arg(arg, char*);
                            buff += tmp_str;
                            p_fmt++;
                            break;
                        default:
                            buff += '%';
                            buff += *p_fmt;
                            p_fmt++;
                            break;
                    }
                    break;
                default:
                    buff += *p_fmt;
                    p_fmt++;
                    break;
            }
        }

        buff += '\n';
        //buff ready
        write(_lfd, buff.c_str(), buff.size());
        return buff.length();
    }

    //private ===================================================>

    //true 未过期 false 过期
    bool Logger::FdIsExpr() {
        time_t curr = time(NULL);
        return curr < _tv;
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

            if(access(_lfp.c_str(), F_OK) < 0) {
            //create log file
            _lfd = open(_lfp.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0660);
            if (_lfd < 0) {
                return false;
            }
        } 
        
        else {
            _lfd = open(_lfp.c_str(), O_WRONLY | O_APPEND);
            if (_lfd < 0) {
                return false;
            }
        }

        }
        return true;
    }



    bool Logger::InitTime() {
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

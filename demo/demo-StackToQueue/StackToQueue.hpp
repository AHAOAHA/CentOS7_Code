/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: StackToQueue.hpp
 * Author: ahaoozhang
 * Date: 2019-09-11 12:39:45 (星期三)
 * Describe: 
 *************************************************/
#ifndef __STACKTOQUEUE_HPP__
#define __SRACKTOQUEUE_HPP__
#include <stack>

namespace AHAOAHA {
    template <class T>
    class qStack {
        public:
            qStack() {}
            ~qStack() {}

            void push(T val) {
                st1.push(val);
            }

            T pop() {
                if (!st2.empty()) {
                    int tmp = st2.top();
                    st2.pop();
                    return tmp;
                }

                //st2为空将st1的内容挪动
                if (st1.empty()) {
                    throw 0;
                }

                while(!st1.empty()) {
                    T tmp = st1.top();
                    st1.pop();

                    st2.push(tmp);
                }

                return pop();
            }

            bool empty() {
                return (st1.empty() && st2.empty());
            }
        private:
            std::stack<T> st1;
            std::stack<T> st2;
    };
}



#endif //

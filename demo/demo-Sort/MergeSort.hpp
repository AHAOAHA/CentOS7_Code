#ifndef __MERGERSORT_HPP__
#define __MERGERSORT_HPP__

#include <vector>
using namespace std;

namespace AHAOAHA {
    template<class T>
    class MergeSort {
        public:
            void Sort(vector<T>& v) {
                _MergeSort(v, 0, v.size());
            }

        private:
            void _MergeSort(vector<T>& v, int begin, int end) {
                if (begin == end)
                    return;
                int div = (begin + end) / 2;

                _MergeSort(v, begin, div);
                _MergeSort(v, div, end);
                Merge(v, begin, div, end);
            }

            //[begin, mid), [mid, end) 为两个有序链表
            void Merge(vector<T>& v, int begin, int mid, int end) {
                //将数组从mid分为两个数组
                vector<T> rhs;
                vector<T> lhs;

                vector<T> ready;

                for (size_t i = begin; i < end; ++i) {
                    if (i < mid) 
                        rhs.push_back(v[i]);
                    
                    else 
                        lhs.push_back(v[i]);
                }

                //合并两个有序数组
                int rindex = 0;
                int lindex = 0;
                while(rindex < rhs.size() || lindex < lhs.size()) {
                    T insert_val = T();
                    if (rindex < rhs.size() && lindex == lhs.size()) {
                        insert_val = rhs[rindex++];
                    } 
                    else if (rindex == rhs.size() && lindex < lhs.size()) {
                        insert_val = lhs[lindex++];
                    }
                    else {
                        if (rhs[rindex] > lhs[lindex]) {
                            insert_val = rhs[rindex++];
                        }
                        else {
                            insert_val = lhs[lindex++];
                        }
                    }
                    

                    //插入insert_val
                    ready.push_back(insert_val);
                }

                for (size_t i = 0; i < ready.size(); ++i) {
                    v[begin++] = ready[i];
                }
            }
    };
}




#endif
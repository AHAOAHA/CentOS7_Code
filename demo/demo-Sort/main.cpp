#include "MergeSort.hpp"
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void EchoVector(const vector<T>& v) {
    for(auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {3,5,1,6,9};
    EchoVector(v);
    AHAOAHA::MergeSort<int>().Sort(v);
    EchoVector(v);
    return 0;
}
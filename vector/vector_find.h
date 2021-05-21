#pragma once
#include <iostream>

template<typename T>
Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const {
//    for (int i = hi - 1; lo < i ; --i) {
//        if(_elem[i] == e){
//            return i;
//        }
//    }
//    return 0;
    clock_t start = clock();
    while ((lo < hi--) && (e != _elem[hi]));
    clock_t end  = clock();
    double programTimes = ((double) end -start) / CLOCKS_PER_SEC;
    std::cout << "vector find ... cost time is : "<< programTimes << std::endl;
    return hi;
}
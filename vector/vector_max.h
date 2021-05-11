#pragma once

//template <typename T>
//Rank Vector<T>::max(Rank lo, Rank hi) {
//    Rank mx  = hi;
//    for (int i = lo; i < hi ; ++i) {
//        if(_elem[i] > _elem[hi]){
//            mx = i;
//        }
//    }
//    return mx;
//}

template <typename T>
Rank Vector<T>::max(Rank lo, Rank hi) {
    Rank mx  = hi;
//    std::cout << "from [lo = " << lo<< ",to hi = " << hi << ")";
    while(lo < hi--)
        if(_elem[hi] > _elem[mx])
            mx = hi;
//    std::cout << "the max index is : " << mx << std::endl;
    return mx;
}
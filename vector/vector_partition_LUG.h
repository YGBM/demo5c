#pragma once

template<typename T>
Rank Vector<T>::partition(Rank lo, Rank hi) {
    swap(_elem[lo], _elem[lo + rand() % (hi - lo)]);
    hi--; T pivot = _elem[lo];
    while(lo < hi) {
        //找出G区域
        while(lo < hi && pivot <= _elem[hi])hi--;
        _elem[lo] = _elem[hi];
        //找到L区域
        while(lo < hi && _elem[lo] <= pivot)lo++;
        _elem[hi]  = _elem[lo];
    }
    _elem[lo] = pivot; return lo;
}
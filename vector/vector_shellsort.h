#pragma once

template <typename T>
void Vector<T>::shellSort(Rank lo, Rank hi) {
    for (int d = 0x3FFFFFFF; 0 < d ; d >>=1) {
        for (int j = lo + d; j <  hi ; ++j) {
            T x = _elem[j]; int i = j -d;
            while( lo <= i && _elem[i] > x)
            { _elem[i + d] = _elem[i]; i-=d;}
            _elem[i + d] = x;
        }
    }
}
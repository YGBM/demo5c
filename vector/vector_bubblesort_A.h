#pragma once

template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
    //1. 归一化下标表示
    // 1.1 自然计数 _size from  1 to n
    // 1.2 the array index from 0 to n-1
    //2. define the times for cycle
    while( lo < --hi) {
        for (Rank i = lo; i < hi; ++i){
            if (_elem[i] > _elem[i + 1]){
                swap(_elem[i], _elem[i + 1]);
            }
        }
    }
}
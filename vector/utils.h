#pragma once

template <typename T>
void swap(T &left,T &right){
    T temp;
    temp = left;
    left = right;
    right = temp;
}
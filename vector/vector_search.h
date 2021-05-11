#pragma once

template <typename T>
Rank Vector<T>::search(const T &e, Rank lo, Rank hi) const {
    while((lo < hi--) && _elem[hi] != e);
    return hi;
}
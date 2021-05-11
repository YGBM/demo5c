#pragma once

template<typename T>
void Vector<T>::quickSort(Rank lo, Rank hi) {
    if (hi - lo < 2) return;
    Rank mi = partition(lo, hi);
    quickSort(lo, mi);
    quickSort(mi + 1, hi);
}
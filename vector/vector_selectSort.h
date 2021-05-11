#pragma once

//template <typename T>
//void Vector<T>::selectSort(Rank lo, Rank hi) {
//    //TODO select sort aglm
//    for (int i = lo; i < hi ; ++i) {
//        Rank maxValueFromlo2hiIndex = max(i,hi);
//        T tmp = _elem[i];
//        _elem[i] = _elem[maxValueFromlo2hiIndex];
//        _elem[maxValueFromlo2hiIndex] = tmp;
//    }
//}

template <typename T>
void Vector<T>::selectSort(Rank lo, Rank hi) {
    while ( lo < --hi)
        swap(_elem[max(lo, hi)],_elem[hi]);
}
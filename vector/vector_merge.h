#pragma once
//
//template<typename T>
//void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
//
//    T container[hi - lo];
//    for (int l = 0; l < hi - lo; ++l) {
//        container[l] = 0;
//    }
//
//    int containerSize = 0;
//    int i = lo;
//    int j = mi;
//
//
//    while (i < mi)
//        //[lo,mi)
//        while (j < hi)
//            //[mi,hi)
//            if (_elem[i] > _elem[j]) {
//                container[containerSize++] = _elem[j++];
//            } else {
//                container[containerSize++] = _elem[i++];
//            }
//    if (i == mi)
//        while(j < hi)
//            container[containerSize++] = _elem[j++];
//
//    if (j == hi)
//        while(i < mi)
//            container[containerSize++] = _elem[i++];
//
//    for (int k = lo; k < hi; ++k) {
//        _elem[k] = container[k-lo];
//    }
//
////    delete [] container;
//}



template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {

    T *container = new T[hi - lo];

    int containerSize = 0;
    int i = lo;
    int j = mi;


    while (i < mi && j < hi)
        //[lo,mi)
        //[mi,hi)
        if (_elem[i] > _elem[j]) {
            container[containerSize++] = _elem[j++];
        } else {
            container[containerSize++] = _elem[i++];
        }

    while (j < hi)
        container[containerSize++] = _elem[j++];


    while (i < mi)
        container[containerSize++] = _elem[i++];

    for (int k = lo; k < hi; ++k) {
        _elem[k] = container[k - lo];
    }

    delete [] container;
}
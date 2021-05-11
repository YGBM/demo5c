#pragma once

//template<typename T>
//void Vector<T>::shrink() {
//    double fillFactor = _size * 0.1 / _capacity;
//    if (fillFactor > 0.5) return; //more than 0.5 not shrink the array
//    T *oldElem = _elem;
//    _elem = new T[_size];
//    for (int i = 0; i < _size; ++i) {
//        _elem[i] = oldElem[i];
//    }
//    delete[] oldElem;
//
//}

template <typename T> void Vector<T>::shrink() { //装填因子过小时压缩向量所占空间
    if ( _capacity < DEFAULT_CAPACITY << 1 ) return; //不致收缩到DEFAULT_CAPACITY以下
    if ( _size << 2 > _capacity ) return; //以25%为界
    T* oldElem = _elem;  _elem = new T[_capacity >>= 1]; //容量减半
    for ( int i = 0; i < _size; i++ ) _elem[i] = oldElem[i]; //复制原向量内容
    delete [] oldElem; //释放原空间
}
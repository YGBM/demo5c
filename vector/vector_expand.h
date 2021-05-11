#pragma once


/**
 * on question : can code  more better?
 *  1. the code format and logical
 *  2. reuse copyFrom method
 *  3. other implementation
 * @tparam T
 */
//template<typename T>
//void Vector<T>::expand() {
//    Rank currnetRank = size();
//    T *temp_elem = new T[currnetRank * 2];
//    for (int i = 0; i < currnetRank; ++i) {
//        temp_elem[i] = _elem[i];
//    }
//    delete[] temp_elem;
//}

/**
 * the book code
 * @tparam T
 */
template<typename T>
void Vector<T>::expand() {//向量空间不足时扩容
   if ( _size < _capacity ) return;//尚未满员时，不必扩容
   if( _capacity < DEFAULT_CAPACITY ) _capacity = DEFAULT_CAPACITY; //不低于最小容量
   T* oldElem = _elem; _elem = new T[_capacity <<=1]; //容量加倍
    for (int i = 0; i < _size; ++i)
        _elem[i] = oldElem[i];//复制原向量内容（T为基本类型，或已重载赋值操作符'='）

    delete [] oldElem;//释放原空间

}
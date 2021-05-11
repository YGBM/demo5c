#pragma once

//template <typename T> void Vector<T>::traverse ( void ( *visit ) ( T& ) ) //借助函数指针机制
//{ for ( int i = 0; i < _size; i++ ) visit ( _elem[i] ); } //遍历向量

template <typename T>
void Vector<T>::traverse() {
    for (int i = 0; i < _size; ++i) std::cout << _elem[i] << std::endl;
}
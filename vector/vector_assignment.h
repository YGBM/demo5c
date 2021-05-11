#pragma once

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& V) {
    if( _elem) delete [] _elem;
    copyFrom(V._elem,0,V.size());
    return *this;
}
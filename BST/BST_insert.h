#pragma once

template <typename T> BinNodePosi(T) BST<T>::insert(const T &e) {
    BinNodePosi(T) & x  =search(e);if(x) return x;
    x = new BinNode<T>(e,_hot);
    _size++;
    updateHeightAbove(x);
    return x;
}
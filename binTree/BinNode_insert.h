#pragma once

template <typename T> BinNode<T> * BinNode<T>::insertAsLC(const T &e) {
    return lc = new BinNode( e,this);
}

template <typename T> BinNode<T> * BinNode<T>::insertAsRC(const T & e) {
    return rc = new BinNode( e, this);
}
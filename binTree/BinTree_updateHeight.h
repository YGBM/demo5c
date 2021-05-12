#pragma once

template <typename T>
int BinTree<T>::updateHeight(BinNode<T> *x) {
    return x->height = 1 + __max(stature(x->lc),stature(x->rc));
}


template <typename T>
void BinTree<T>::updateHeightAbove(BinNode<T> *x) {
    while(x){
        updateHeight(x);
        x = x->parent;
    }
}
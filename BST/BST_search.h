#pragma once

template <typename T> BinNodePosi(T) & BST<T>::search(const T &e) {
    if(!_root || e == _root->data) {_hot = NULL;return _root;}
    for(_hot = _root;;){
        BinNodePosi(T)& c = (e<_hot->data)? _hot->lc:_hot->rc;
        if(!c || e == c->data) return c;_hot = c;
    }
}
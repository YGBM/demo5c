#pragma once

template <typename T>
int BinTree<T>::remove(BinNode<T> *x) {
    FromParentTo(*x) = NULL;
    updateHeightAbove(x->parent);
    int n = removeAt(x);_size -=n; return n;
}

template <typename T>
static int removeAt(BinNodePosi(T) x){
    if(!x) return 0;
    int n = 1+removeAt(x->lc) + removeAt(x->rc);
    release ( x->data ); release ( x ); return n; //释放被摘除节点，并返回删除节点总数

}
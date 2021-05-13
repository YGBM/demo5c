#pragma once

#include "BinTree.h"
#include "_share/rand.h"
#include "_share/print.h"
#include "_share/double_Elem.h"
#include "_share/increase_Elem.h"
#include <iostream>
using namespace std;

template<typename T>
bool randomBinTree(BinTree<T> &bt, BinNodePosi(T)x, int h) {
    if (0 >= h) return false;
    if (0 < dice(h))
        randomBinTree(bt, bt.insertAsLC(x, dice((T) h * h * h)), h - 1);
    if (0 < dice(h))
        randomBinTree(bt, bt.insertAsRC(x, dice((T) h * h * h)), h - 1);
    return true;
}

// 在二叉树中随机确定一个节点位置
template <typename T> BinNodePosi(T) randomPosiInBinTree ( BinNodePosi(T) root ) {
    if ( !HasChild ( *root ) ) return root;
    if ( !HasLChild ( *root ) )
        return dice ( 6 ) ? randomPosiInBinTree ( root->rc ) : root;
    if ( !HasRChild ( *root ) )
        return dice ( 6 ) ? randomPosiInBinTree ( root->lc ) : root;
    return dice ( 2 ) ?
           randomPosiInBinTree ( root->lc ) :
           randomPosiInBinTree ( root->rc ) ;
}

int main() {
    int h = 6;
    BinTree<int> bt;
    bt.insertAsRoot(dice(h * h * h));print(bt);
    randomBinTree(bt,bt.root(),h);print(bt);
    while (!bt.empty()) {
        BinNodePosi(int) p = randomPosiInBinTree ( bt.root() ); //随机选择一个节点
        if ( dice ( 2 ) ) {
            printf ( "removing " ); print ( p->data ); printf ( " ...\n" );
            printf ( "%d node(s) removed\n", bt.remove ( p ) ); print ( bt );
        } else {
            printf ( "releasing " ); print ( p->data ); printf ( " ...\n" );
            BinTree<int>* S = bt.secede ( p ); print ( S );
            printf ( "%d node(s) released\n", S->size() ); release ( S ); print ( bt );
        }
    }
//    bt.travPre ( Double<int>() ); bt.travPre ( Increase<int>()); print ( bt );

}

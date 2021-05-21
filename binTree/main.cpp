#pragma once

#include "BinTree.h"
#include "_share/rand.h"
#include "_share/print.h"
#include "_share/double_Elem.h"
#include "_share/increase_Elem.h"
#include <iostream>
using namespace std;

int testID = 0; //测试编号

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

template <typename T> void   testBinTree ( int h ) { //测试二叉树
    printf ( "\n  ==== Test %2d. Generate a binTree of height <= %d \n", testID++, h );
    BinTree<T> bt; print ( bt );
    bt.insertAsRoot ( dice ( ( T ) h * h * h ) ); print ( bt );
    randomBinTree<T> ( bt, bt.root(), h ); print ( bt );
    printf ( "\n  ==== Test %2d. Double and increase all nodes by traversal\n", testID++ );
    Double<T> dt;
    bt.travPre (dt );// bt.travPre ( Increase<T>() ); print ( bt );
//    bt.travIn ( Double<T>() ); bt.travIn ( Increase<T>() ); print ( bt );
//    bt.travPost ( Double<T>() ); bt.travPost ( Increase<T>() ); print ( bt );
//    bt.travLevel ( Double<T>() ); bt.travLevel ( Increase<T>() ); print ( bt );
//    Hailstone<T> hs; bt.travIn ( hs ); print ( bt );
    printf ( "\n  ==== Test %2d. Remove/release subtrees in the Tree\n", testID++ );
    while ( !bt.empty() ) {
        BinNodePosi(T) p = randomPosiInBinTree ( bt.root() ); //随机选择一个节点
        if ( dice ( 2 ) ) {
            printf ( "removing " ); print ( p->data ); printf ( " ...\n" );
            printf ( "%d node(s) removed\n", bt.remove ( p ) ); print ( bt );
        } else {
            printf ( "releasing " ); print ( p->data ); printf ( " ...\n" );
            BinTree<T>* S = bt.secede ( p ); print ( S );
            printf ( "%d node(s) released\n", S->size() ); release ( S ); print ( bt );
        }
    }
}


int main() {
    int h = 6;
//    srand ( ( unsigned int ) time ( NULL ) );
    testBinTree<int> ( h ); //元素类型可以在这里任意选择
//    BinTree<int> bt;
//    BinNodePosi(int) root  = bt.insertAsRoot(1);
////    error call
////    BinNodePosi(int) rlc = root->insertAsLC(2);
////    BinNodePosi(int) rrc = root->insertAsRC(3);
//    BinNodePosi(int) aaa = bt.insertAsRC(root, 2);
//    bt.insertAsLC(root,3);
////    bt.insertAsLC(a,123);
//    bt.insertAsLC(aaa,123);
//
////    bt.insertAsLC()
//    print(bt);
    return 0;
}

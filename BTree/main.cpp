
#include "BTree.h"
#include <iostream>
#include "_share/rand.h"
#include "_share/print.h"
using namespace std;

/******************************************************************************************
* Test a BTree
******************************************************************************************/
template <typename T> void  testBTree ( int order, int n ) {
    BTree<T> bt ( order );
    while ( bt.size() < n ) {
        T e = dice ( ( T ) n * 3 ); //[0, 3n)范围内的e
        switch ( dice ( 3 ) ) {
            case 0: { //查找，成功率 <= 33.3%
                printf ( "Searching for " ); print ( e ); printf ( " ... " );
                BTNodePosi(T) p = bt.search ( e );
                printf ( p ? "Found\n" : "Not found\n" );
                break;
            }
            case 1: { //删除，成功率 <= 33.3%
                printf ( "Removing " ); print ( e ); printf ( " ... " );
                if(bt.remove ( e )) { printf ( "Done\n" ); print ( bt );} else{ printf ( "Not exists\n" );};
                break;
            }
            default: {//插入，成功率 == 100%
                printf ( "Inserting " ); print ( e ); printf ( " ... " );
                int oldSize = bt.size();
                if(bt.insert ( e )){printf ( "Done\n" ); print ( bt ); }else{printf ( "Dup key\n" );}
                break;
            }
        }
    }
    while ( bt.size() > 0 ) {
        T e = dice ( ( T ) n * 3 ); //[0, 3n)范围内的e
        printf ( "Removing " ); print ( e ); printf ( " ... " );
        if(bt.remove ( e )){printf ( "Done\n" ); print ( bt );}else{printf ( "not exists\n" );}
    }
}

int main(){
    int order = 6;
    int size = 6;
    testBTree<int> ( order,size ); //元素类型、比较器可以在这里任意选择
}
#pragma once

#include "BinNode.h"  //引入二叉树节点类

template <typename T> class BinTree{  //二叉树模板类
protected:
    int _size; BinNodePosi(T) _root;   //规模、根节点
    virtual int updateHeight( BinNodePosi(T) x);  //更新节点x的高度
    void updateHeightAbove(BinNodePosi(T) x);   //更新节点x及其祖先的高度

public:
    BinTree():_size(0),_root(NULL) {}  //构造函数
    ~BinTree() {if (0 < _size) remove(_root);}  //析构函数
    int size()const {return _size;}   //规模
    bool empty() const {return !_root; }   //判空
    BinNodePosi(T) root() const { return _root; } //树根
    BinNodePosi(T) insertAsRoot ( T const& e ); //插入根节点
    BinNodePosi(T) insertAsLC ( BinNodePosi(T) x, T const& e ); //e作为x的左孩子（原无）插入
    BinNodePosi(T) insertAsRC ( BinNodePosi(T) x, T const& e ); //e作为x的右孩子（原无）插入
    BinNodePosi(T) attachAsLC ( BinNodePosi(T) x, BinTree<T>* & ); //T作为x左子树接入
    BinNodePosi(T) attachAsRC ( BinNodePosi(T) x, BinTree<T>* & ); //T作为x右子树接入
    int remove (BinNodePosi(T) x);
    BinTree<T>* secede(BinNodePosi(T) x);
    template <typename VST> void travLevel(VST &visit){ if(_root) _root ->travLevel(visit);}
    template <typename VST> void travPre(VST &visit){ if(_root) _root ->travPre(visit);}
    template <typename VST> void travIn(VST &visit){ if(_root) _root ->travIn(visit);}
    template <typename VST> void travPost(VST &visit){ if(_root) _root ->travPost(visit);}
    bool operator< (BinTree<T> const& t)
    {return _root && t._root && lt ( _root, t._root ); }
    bool operator== ( BinTree<T> const& t ) //判等器
    { return _root && t._root && ( _root == t._root ); }

};


#include "BinTree_implementation.h"
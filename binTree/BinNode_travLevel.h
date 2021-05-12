#pragma once

#include <queue> //引入队列

template <typename T> template <typename VST>  //元素类型、操作器
void BinNode<T>::travLevel(VST &) {  //二叉树层次遍历算法
    std::queue<BinNodePosi(T)> Q;   //辅助队列
    Q.push(this);    //根节点入队
    while(!Q.empty()) {   //在队列再次变空之前，反复迭代
        BinNodePosi(T) x = Q.pop(); visit(x->data);  //取出队首节点并访问之
        if(HasLChild(*x)) Q.push(x->lc);   //左孩子入队
        if(HasRChild(*x)) Q.push(x->rc);  //右孩子入队
    }
}
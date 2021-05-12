#pragma once
#include <stack>

template <typename T>
static void goToLeftmostLeaf(std::stack<BinNodePosi(T)> &S){
    while(BinNodePosi(T) x = S.top())
        if(HasLChild(*x)) {
            if(HasRChild(*x)) S.push(x->rc);
            S.push(x->lc);
        } else
            S.push(x->rc);
    S.pop();
}

template <typename T,typename VST>
void travPost_I(BinNodePosi(T) x,VST& visit){
    std::stack<BinNodePosi(T)> S;
    if (x) S.push(x);
    while(!S.empty()) {
        if(S.top() != x->parent)
            goToLeftmostLeaf(S);
        x = S.pop(); visit(x->data);
    }
}
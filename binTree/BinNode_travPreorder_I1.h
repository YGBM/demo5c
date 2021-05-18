#pragma once
#include <stack>


template <typename  T,typename VST>
void travPre_I1(BinNodePosi(T) x,VST& visit){
    std::stack<BinNodePosi(T)> S;
    if (x) S.push(x);
    while (!S.empty()){
        x = S.top();
        S.pop();
        visit(x->data);
        if(HasRChild(*x)) S.push(x->rc);if(HasLChild(*x))S.push(x->lc);
    }
}
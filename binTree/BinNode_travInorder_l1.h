#pragma once
#include <stack>

template <typename T>
static void goAlongVine(BinNodePosi(T) x,std::stack<BinNodePosi(T)> &S){
    while (x) {S.push(x);x = x->lc;}
}

template <typename T,typename VST>
void travIn(BinNodePosi(T) x,VST& visit) {
    std::stack<BinNodePosi(T)> S;
    while(true) {
        goAlongVine(x,S);
        if(S.empty()) break;
        x = S.pop();visit(x->data);
        x = x->rc;
    }
}

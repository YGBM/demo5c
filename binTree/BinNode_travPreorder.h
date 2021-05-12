#pragma once

#include "BinNode_travPreorder_I1.h"

template <typename T> template <typename VST>
void BinNode<T>::travPre(VST &visit) {
    switch(1){
        case 1:travPre_I1(this,visit);break;
    }
}
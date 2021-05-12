#pragma once

#include "BinNode_travPostorder_I.h"

template <typename T> template <typename VST>
void BinNode<T>::travPost(VST &visit) {
    switch (1) {
        case 1:travPost_I(this,visit);break;
    }
}
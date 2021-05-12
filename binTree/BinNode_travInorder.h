#pragma once

#include "BinNode_travInorder_l1.h"

template <typename T> template <typename VST>
void BinNode<T>::travIn(VST & visit) {
    switch ( 1 ) { //此处暂随机选择以做测试，共五种选择
        case 1:
            travIn_I1(this, visit);
            break; //迭代版#1
    }
}
#pragma once

template<typename T>

void Vector<T>::sort(Rank lo, Rank hi) {
    clock_t start = clock();
    switch (3) {
        case 1:
            //冒泡。。。。
            std::cout << "start bubbleSort ..." << std::endl;
            bubbleSort(lo, hi);
            break;
        case 2:
            //从后往前 选择最大的放在指针位置
            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // [--- select max value p and swap(_elem[k],_elem[p_i]) --- ]   [ -----  sorted  ---- ]
            // X x . . . . . . . . . . . . . . . . . . . . . . . . . . . . x . . . . . . . . . . x X
            // |                                                        <- |                       |
            // lo                                                          k (current point)       hi
            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            std::cout << "start selectSort ..." << std::endl;
            selectSort(lo, hi);
            break;
        case 3:
            std::cout << "start mergeSort ..." << std::endl;
            mergeSort(lo, hi);
            break;
        case 4:
            // pivot:左侧/右侧的元素，均不比它更大/更小
            // 以轴点为界，自然划分:max( [0,mi) ) <= min( (mi, hi) )
            // 前缀、后缀各自(递归)排序之后，原序列自然有序
            // sorted(S) = sorted(SL) + sorted(SR)
            // mergesort的难点在于合，而quicksort在于分
            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // X x . . . . . . . x . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . x X
            // |                 |                                                                 |
            // lo                pivot                                                             hi
            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            std::cout << "start quickSort ..." << std::endl;
            quickSort(lo,hi);
            break;
        case 5:
            //从前往后 选择合适位置插入指针处数据
            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // [--- sorted --- ]   [ -select position  and insert(search(_elem[k],lo,k),_elem[k])- ]
            // X x . . . . . . . x . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . x X
            // |                 | ->                                                              |
            // lo                k (current point)                                                 hi
            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            std::cout << "start insertSort ..." << std::endl;
            insertSort(lo,hi);
            break;
        case 6:
            std::cout << "start shellSort ..." << std::endl;
            shellSort(lo, hi);
            break;
    }

    clock_t end = clock();
    double programTimes = ((double) end - start) / CLOCKS_PER_SEC;
    std::cout << "vector sort ... cost time is : " << programTimes << std::endl;
}

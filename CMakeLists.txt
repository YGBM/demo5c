cmake_minimum_required(VERSION 3.13)
project(demo05c)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_BUILD_TYPE Debug)
include_directories(.)
include_directories(vector)
include_directories(binTree)
include_directories(data)

add_executable(
        vector_implementation.h
        vector/vector.h
        vector/vector_constructor_by_coping.h
        vector/vector_find.h
        vector/vector_search.h
        vector/vector_expand.h
        vector/vector_shrink.h
        vector/vector_sort.h
        vector/vector_traverse.h
        vector/vector_selectSort.h
        vector/vector_bubblesort_A.h
        vector/utils.h
        vector/vector_bubblesort_B.h
        vector/vector_insert.h
        vector/vector_merge.h
        vector/vector_mergesort.h
        vector/vector_quicksort.h
        vector/vector_insertsort.h
        vector/vector_partition_LUG.h
        vector/vector_shellsort.h
        vector/vector_bracket.h
        vector/vector_assignment.h
        vector/vector_unsort.h
        vector/vector_deduplicate.h
        vector/vector_remove.h
        vector/vector_removeinterval.h
        vector/vector_uniquify.h
#        vector/main.cpp
        binTree/main.cpp
        binTree/BinTree_implementation.h
        binTree/BinTree.h
        binTree/BinNode.h
        binTree/BinNode_implementation.h
        binTree/BinNode_macro.h
        binTree/BinNode_macro_Basic.h
        binTree/BinNode_size.h
        binTree/BinNode_insert.h
        binTree/BinNode_succ.h
        binTree/BinNode_zig.h
        binTree/BinNode_macro_AVL.h
        binTree/BinNode_zag.h
        binTree/BinNode_travLevel.h
        binTree/BinNode_travInorder.h
        binTree/BinNode_travInorder_l1.h
        binTree/BinNode_travPostorder.h
        binTree/BinNode_travPostorder_I.h
        binTree/BinNode_travPreorder.h
        binTree/BinNode_travPreorder_I1.h
        binTree/BinTree_remove.h
        binTree/BinTree_secede.h
        binTree/BinTree_updateHeight.h
        binTree/BinTree_insert.h
        binTree/BinTree_attach.h
        _share/rand.h
        _share/print.h
        _share/print_implementation.h
        _share/print_binNode.h
        _share/print_bintree.h
        _share/release.h
        BitMap/Bitmap.h
        BitMap/Bitmap_O1_init.h
        _share/print_basic.cpp
        _share/double_Elem.h
        _share/increase_Elem.h
        BTree/BTNode.h
        BTree/BTree.h
        BTree/BTree_implementation.h
        BTree/BTree_insert.h
#        BTree/main.cpp
        BTree/BTree_solveOverflow.h BTree/BTree_solveUnderflow.h BTree/BTree_remove.h BTree/BTree_search.h _share/print_btree.h BST/BST.h BST/BST_implementation.h BST/BST_connect34.h
#        BST/main.cpp
        BST/BST_insert.h BST/BST_RotateAt.h BST/BST_search.h BST/BST_remove.h BST/BST_removeAt.h)
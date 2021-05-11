cmake_minimum_required(VERSION 3.13)
project(demo05c)

set(CMAKE_CXX_STANDARD 14)
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
        vector/main.cpp binTree/main.cpp binTree/BinTree_implementation.h binTree/BinTree.h binTree/BinNode.h binTree/BinNode_implementation.h binTree/BinNode_macro.h binTree/BinNode_macro_Basic.h binTree/BinNode_size.h binTree/BinNode_insert.h binTree/BinNode_succ.h)
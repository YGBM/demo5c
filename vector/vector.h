#pragma once

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class Vector {

protected:
    Rank _size;int _capacity; T* _elem;//规模、容量、数据区
    void copyFrom (T const* A,Rank lo,Rank hi);//复制数组区间A[lo, hi)
    void expand();//空间不足时扩容
    void shrink();//装填因子过小时压缩
    bool bubble(Rank lo, Rank hi); //扫描交换
    void bubbleSort(Rank lo,Rank hi);//起泡排序算法
    Rank max (Rank lo, Rank hi);//选取最大元素
    void selectSort(Rank lo,Rank hi);//选择排序算法
    void merge(Rank lo,Rank mi,Rank hi);//归并算法
    void mergeSort(Rank lo,Rank hi);//归并排序算法
    void heapSort(Rank lo,Rank hi);//堆排序（稍后结合完全堆讲解）
    Rank partition(Rank lo,Rank hi);//轴点构造算法
    void quickSort(Rank lo,Rank hi);//快速排序算法
    void shellSort(Rank lo,Rank hi);//希尔排序算法
    void insertSort(Rank lo,Rank hi);//插入排序


public:
// 构造函数
    Vector(int c = DEFAULT_CAPACITY,int s = 0,T v = 0) //容量为c、规模为s、所有元素初始为v
    {_elem = new T[_capacity = c];for(_size = 0; _size < s; _elem[_size++] = v);}//s<=c
    Vector(T const* A,Rank n){copyFrom(A,0,n);};//数组整体复制
    Vector(T const* A, Rank lo,Rank hi){copyFrom(A,lo,hi);}//区间
    Vector(Vector<T> const& v){copyFrom(v._elem,0,v._size);}//向量整体复制
    Vector(Vector<T> const& v,Rank lo,Rank hi) {copyFrom(v._elem,lo,hi);}//区间
// 析构函数
    ~Vector() {delete [] _elem;}//释放内部空间
// 只读访问接口
    Rank size() const{return _size;}//规模
    bool empty() const{return !_size;}//判空
    Rank find(T const& e)const {return find(e,0,_size);}//无序向量整体查找
    Rank find(T const& e,Rank lo,Rank hi)const;//无序向量区间查找
    Rank search(T const& e) const//有序向量整体查找
    {return ( 0>= _size)? -1:search(e,0,_size);}
    Rank search(T const& e,Rank lo,Rank hi)const;//有序向量区间查找
// 可写访问接口
    T& operator[](Rank r);
    const T&operator[](Rank r) const;
    Vector<T> & operator=(Vector<T> const&);
    T remove(Rank r);
    int remove(Rank lo,Rank hi);
    Rank insert(Rank r,T const&e);
    Rank insert(T const&e){return insert(_size,e);}
    void sort(Rank lo,Rank hi);
    void sort() {sort(0 , _size);}
    void unsort(Rank lo,Rank hi);
    void unort(){unsort(0,_size);}
    int deduplicate();
    int uniquify();
//    void traverse(void (*)(T&));
    void traverse();

};


#include "vector_implementation.h"
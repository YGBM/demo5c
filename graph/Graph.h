#pragma once

#include <stack>
#include <iostream>
using namespace std;

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus; //顶点状态
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType; //边在遍历树中所属的类型

template <typename Tv,typename Te>
class Graph{
private:
    void reset(){
        for (int i = 0; i < n; ++i) {
            status(i) = UNDISCOVERED;dTime(i) = fTime(i) = -1;
            parent(i) = -1;priority(i) = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if(exists(i,j)) type(i,j) = UNDETERMINED;
            }
        }
    }
    void BFS(int,int&); //（连通域）广度优先搜索算法
    void DFS(int,int&); //（连通域）深度优先搜索算法
    void BCC(int,int&,stack<int>&);  //（连通域）基于DFS的双连通分量分解算法
    bool TSort(int,int&,stack<Tv>*);  //（连通域）基于DFS的拓扑排序算法
    template <typename PU> void PFS(int,PU);  //（连通域）优先级搜索框架


public:
    int n;
    virtual int insert(Tv const&) = 0;
    virtual Tv remove(int ) = 0;
    virtual Tv& vertex(int) = 0;
    virtual int inDegree(int) = 0;
    virtual int outDegree(int)= 0;
    virtual int firstNbr (int) = 0;
    virtual int nextNbr(int) = 0;
    virtual VStatus status(int) = 0;
    virtual int& dTime(int) = 0;
    virtual int& fTime(int) = 0;
    virtual int& parent(int)= 0;
    virtual int& priority(int) = 0;

    int e;
    virtual bool exists(int,int) = 0;
    virtual void insert(Te const&,int,int,int) = 0;
    virtual Te remove(int ,int) = 0;
    virtual EType & type(int,int) = 0;
    virtual Te& edge(int,int) = 0;
    virtual int& weight(int,int) = 0;
//    算法
    void bfs(int);
    void dfs(int);
    void bcc(int);
    stack<Tv>* tSort(int);
    void prim(int);
    void dijkstra(int);
    template <typename PU>void pfs(int,PU);

};

#include "Graph_implementation.h"
#pragma once

#include <stack>
#include <queue>


template <typename Tv,typename Te>
void Graph<Tv,Te>::bfs(int s) {
    reset();int clock = 0;int v = s;
    do
        if(UNDISCOVERED == status(v))
            BFS(v,clock);
    while(s != (v = (++v % n)));

}

template <typename Tv,typename Te>
void Graph<Tv,Te>::BFS(int v, int & clock) {
    queue<int> Q;
    status(v) = DISCOVERED;Q.push(v);
    while(!Q.empty()){
        int v = Q.front();Q.pop();dTime(v) = ++clock;
        for (int u = firstNbr(v); -1 < u; u = nextNbr(v,u)) {
            if(UNDISCOVERED == status(u)){
                status(u) = DISCOVERED;Q.push(u);
                type(v,u) = TREE;parent(u) = v;
            }else{
                type(v,u) = CROSS;
            }
            status(v) = VISITED;
        }

    }
}
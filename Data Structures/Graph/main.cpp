#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

int main() {
    int arr[] = {1, 5, 10, 15, 20, 25, 30};
    vector<int> v(arr, arr + 7);

    Graph *g = new Graph(v);
    g->addEdge(1, 0); 
    g->addEdge(3, 0); g->addEdge(3, 1); g->addEdge(3, 6);
    g->addEdge(5, 6);
    g->addEdge(6, 2); g->addEdge(6, 4);
    g->print();
    g->bfs(3);
    g->dfs(3);

    return 0;
}
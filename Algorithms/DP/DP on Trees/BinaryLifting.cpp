#include <bits/stdc++.h> 
using namespace std; 

/*
    Time:  O(n log n) - preprocess
           O(log n)   - query
    Space: O(n logn)
*/

void findAncestor(int u, int p) {
    p[u][0] = p;
    for(int i = 1; i <= logN; i++)
        p[u][i] = p[ p[u][i-1] ][i-1];
}

void dfs(int u) {
    in[u] = ++t;
    for(int i = 0; i < g[u].size(); i++)
        findAncestor(g[u][i], u), dfs(g[u][i]); // It is a Tree: no need to check if the node has already been visited
    out[u] = ++t;
}

bool isAncestor(int u, int v) { return in[u] >= in[v] && out[u] <= out[v]; }

int lca(int u, int v) {
    if(isAncestor(v, u)) return v;

    //for(int i = logN; i >= 0 && !isAncestor(u,v); i--) u = p[u][i];

    //return p[u][0];
}
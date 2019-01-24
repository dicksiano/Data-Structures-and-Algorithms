#include <bits/stdc++.h> 
using namespace std; 

/*
    Time:  O(n)
    Space: O(n)
*/

vector<int> i, o;
vector<vector<int> > g;

void in(int u) {
    if(i[u] != -1) return i[u];

    for(int i = 0; i < g[u].size(); i++)
        i[u] = max(i[u], 1 + in( g[u][i] );
}

void out(int u) {
    if(o[u] != -1) return o[u];

    int max1 = -1, max2 = -1;
    for(int i = 0; i < g[u].size(); i++)
        max1 = max(max1, in( g[u][i] ));
    for(int i = 0; i < g[u].size(); i++)
        if(in( g[u][i] ) <= max1) max2 = max(max2, in( g[u][i] ));

    for(int i = 0, child = g[u][i]; i < g[u].size(); i++, child = g[u][i]) {
        o[child] = 1 + max(o[u], 1 + (i[child] == max1 ? max2 : max1) );
        out(child);
    }    
}


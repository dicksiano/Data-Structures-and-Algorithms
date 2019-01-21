#include <bits/stdc++.h> 
using namespace std; 

#define MAX_NODES 9999

int dp[MAX_NODES];                                       // Maximum sum path starting on that node
int v[] = { 3, 2, 1, 10, 1, 3, 9, 1, 5, 3, 4, 5, 9, 8 }; // Value of each node
vector< vector<int> > g;

void dfs(int u) {
    int maxi = 0, child;
    for(int i = 0; i < g[u].size(); i++) {
        child = g[u][i];
        dfs(child);
        maxi = max(maxi, dp[ child ]);
    }
    dp[u] = v[u] + maxi;
}

int main() {
    g.assign(14, vector<int>());
    g[0].push_back(1); g[0].push_back(2); g[0].push_back(3); 
    g[1].push_back(4); g[1].push_back(5);  
    g[2].push_back(6);  
    g[3].push_back(7); g[3].push_back(8); g[3].push_back(9);  
    g[4].push_back(10); g[4].push_back(11);  
    g[6].push_back(12);  
    g[6].push_back(13); 

    dfs(0);
    cout << dp[0] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int> > g, vector<vector<int> > adjMatrix, int s, int t, int p[]) {
    queue<int> q; q.push(s);
    vector<int> visited(g.size(), 0);
    p[s] = -1;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        visited[u] = 1;

        for(int i = 0; i < g[u].size(); i++) 
            if(!visited[ g[u][i] ] && adjMatrix[u][ g[u][i] ] > 0) { q.push( g[u][i] ); p[ g[u][i] ] = u; }
    }
    return visited[t];
}
int edmondsKarp(vector<vector<int> > g, vector<vector<int> > adjMatrix, int s, int t) {
    int p[g.size()], mf = 0;

    for(int pathFlow = INT_MAX; bfs(g, adjMatrix, s, t, p); pathFlow = INT_MAX) {                                   // While there's a path betweem s and t
        for(int i = t; i != s; i = p[i]) pathFlow = min(pathFlow, adjMatrix[ p[i] ][i]);                            // Find bottleneck
        for(int i = t; i != s; i = p[i]) { adjMatrix[ p[i] ][i] -= pathFlow; adjMatrix[i][ p[i] ] += pathFlow; }    // Update edges
        mf += pathFlow;                                                                                             // Update maxFlow
    }
    return mf;
}

int main() {
    vector<vector<int> > g { {1 ,2},
                             {0, 2, 3},
                             {0, 1, 4},
                             {1, 2, 4, 5},
                             {2, 3, 5},
                             {3, 4}
                        };
    vector<vector<int> > adjMatrix{ {0, 16, 13, 0, 0, 0}, 
                            {0, 0, 10, 12, 0, 0}, 
                            {0, 4, 0, 0, 14, 0}, 
                            {0, 0, 9, 0, 0, 20}, 
                            {0, 0, 0, 7, 0, 4}, 
                            {0, 0, 0, 0, 0, 0} 
                        }; 
  
    cout << edmondsKarp(g, adjMatrix, 0, 5) << endl; 
  
    return 0; 
} 
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int> > g, vector<vector<int> > &adjMatrix, vector<int> &dist, int flow, int u, int t) {
    if(u == t) return flow;
        
    for(int i = 0; i < g[u].size(); i++)
        if( (dist[ g[u][i] ] == dist[u] + 1) && adjMatrix[u][ g[u][i] ] > 0) {
            int currFlow = dfs(g, adjMatrix, dist, min(flow, adjMatrix[u][ g[u][i] ]), g[u][i], t);
            if(currFlow > 0) {
                adjMatrix[u][ g[u][i] ] -= currFlow;
                adjMatrix[ g[u][i] ][u] += currFlow;
                return currFlow;
            }
        }
    return 0;
}

int bfs(vector<vector<int> > g, vector<vector<int> > &adjMatrix, vector<int> &dist, int s, int t) {
    queue<int> q; q.push(s);
    dist.assign(g.size(), -1); dist[s] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < g[u].size(); i++) 
            if(dist[ g[u][i] ] == -1 && adjMatrix[u][ g[u][i] ] > 0) {q.push(g[u][i]); dist[ g[u][i] ] = dist[u] + 1; }
    }
    return dist[t] != -1;
}

int dinic(vector<vector<int> > g, vector<vector<int> > &adjMatrix, int s, int t) {
    int mf = 0, flow; 
    vector<int> dist;

    while( bfs(g, adjMatrix, dist, s, t) ) 
        while( flow = dfs(g, adjMatrix, dist, INT_MAX, s, t) ) 
            mf += flow;
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
  
    cout << dinic(g, adjMatrix, 0, 5) << endl; 
  
    return 0; 
} 
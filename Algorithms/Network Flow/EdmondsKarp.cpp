#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int> > rg, int s, int t, int p[]) {
    queue<int> q; q.push(s);
    vector<int> visited(rg.size(), 0);
    p[s] = -1;

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        visited[curr] = 1;

        for(int i = 0; i < rg.size(); i++) 
            if(!visited[i] && rg[curr][i] > 0) { q.push(i); p[i] = curr; }
    }
    return (visited[t]);
}
int edmondsKarp(vector<vector<int> > g, int s, int t) {
    vector< vector<int> > rg(g);
    int p[g.size()], mf = 0;

    for(int pathFlow = INT_MAX; bfs(rg, s, t, p); pathFlow = INT_MAX) {                             // While there's a path betweem s and t
        for(int i = t; i != s; i = p[i]) pathFlow = min(pathFlow, rg[ p[i] ][i]);                   // Find bottleneck
        for(int i = t; i != s; i = p[i]) { rg[ p[i] ][i] -= pathFlow; rg[i][ p[i] ] += pathFlow; }  // Update edges
        mf += pathFlow;                                                                             // Update maxFlow
    }
    return mf;
}

int main() 
{ 
    // Let us create a graph shown in the above example 
    vector<vector<int> > g{ {0, 16, 13, 0, 0, 0}, 
                            {0, 0, 10, 12, 0, 0}, 
                            {0, 4, 0, 0, 14, 0}, 
                            {0, 0, 9, 0, 0, 20}, 
                            {0, 0, 0, 7, 0, 4}, 
                            {0, 0, 0, 0, 0, 0} 
                        }; 
  
    cout << edmondsKarp(g, 0, 5) << endl; 
  
    return 0; 
} 
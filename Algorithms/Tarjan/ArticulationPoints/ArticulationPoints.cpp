#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        Graph(vector<char> v) : v(v) {
            e.assign(v.size(), vector<int>());
        }

        void addEdge(int i, int j) { 
            e[i].push_back(j); 
            e[j].push_back(i);
        }

        void articulationPoint(int x) {
            int s = 0;

            vector<int> started(v.size(), 0);
            vector<int> m(v.size(), 0);
            vector<int> parent(v.size(), 0);
            vector<int> numChild(v.size(), 0);

            parent[x] = -1;

            dfs(x, s, started, m, parent, numChild);

            vector<int> ap(v.size(), 0);
            ap[x] = numChild[x] > 1;
            for(int i = 0; i < v.size(); i++) 
                if(i != x) 
                    ap[ parent[i] ] = ap[ parent[i] ] || (m[i] >= started[ parent[i] ]);   

            for(int i = 0; i < v.size(); i++) 
                if(ap[i]) 
                    cout << v[i] << endl;
        }

    private:
        vector<char> v;
        vector< vector<int> > e;

        void dfs(int u, int &s, vector<int> &started, vector<int> &m, vector<int> &parent, vector<int> &numChild) {
            started[u] = m[u] = ++s;

            for(int i = 0; i < e[u].size(); i++) {
                if( started[ e[u][i] ] == 0 ) {
                    parent[ e[u][i] ] = u;
                    numChild[u]++;
                    dfs(e[u][i], s, started, m, parent, numChild);
                    m[u] = min(m[u], m[ e[u][i] ] );
                } else {
                    if( u != parent[ e[u][i] ] ) 
                        m[u] = min(m[u], started[ e[u][i] ] );
                }
            }
        }   
};

int main() {
    vector<char> v; 
    v.push_back('A');  
    v.push_back('B');  
    v.push_back('C');  
    v.push_back('D');  
    v.push_back('E');  
    v.push_back('F');  

    Graph *g = new Graph(v);
    g->addEdge(0, 1); g->addEdge(0, 5); g->addEdge(0, 4);
    g->addEdge(1, 2);  
    g->addEdge(2, 0); g->addEdge(2, 5); 
    g->addEdge(3, 4);

    g->articulationPoint(0);

    return 0;
}
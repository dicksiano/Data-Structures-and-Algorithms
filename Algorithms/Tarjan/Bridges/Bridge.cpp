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

            parent[x] = -1;

            dfs(x, s, started, m, parent);
        }

    private:
        vector<char> v;
        vector< vector<int> > e;

        void dfs(int u, int &s, vector<int> &started, vector<int> &m, vector<int> &parent) {
            started[u] = m[u] = ++s;

            for(int i = 0; i < e[u].size(); i++) {
                if( started[ e[u][i] ] == 0 ) {
                    parent[ e[u][i] ] = u;
                    dfs(e[u][i], s, started, m, parent);
                    m[u] = min(m[u], m[ e[u][i] ] );
                    
                    if(m[ e[u][i] ] == started[ e[u][i] ]) 
                        cout << "<" << v[u] << ", " << v[ e[u][i] ] << ">\n";
                } else {
                    if( e[u][i] != parent[ u ] ) 
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
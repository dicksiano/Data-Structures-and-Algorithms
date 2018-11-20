#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        Graph(vector<int> v) : v(v) {
            e.assign(v.size(), vector<int>());
        }

        void addEdge(int i, int j) { e[i].push_back(j); }

        void bfs(int i) {
            vector<int> visited(v.size(), 0);
            bfs(i, visited);
        }

        void dfs(int i) {
            vector<int> visited(v.size(), 0);
            dfs(i, visited);
        }

        void print() {
            for(int i = 0; i < v.size(); i++) {
                cout << std::setw(2) << v[i] << ": ";
                for(int j = 0; j < e[i].size(); j++)
                    cout << std::setw(2) << v[ e[i][j] ] << " ";
                cout << endl;
            }
        }

    private:
        vector<int> v;
        vector< vector<int> > e;

        void bfs(int u, vector<int> &visited) {
            queue<int> q; q.push(u);

            while(!q.empty()) {
                int curr = q.front(); q.pop();
                visit(curr);
                visited[curr] = 1;

                for(int i = 0; i < e[curr].size(); i++) 
                    if(!visited[ e[curr][i] ]) q.push( e[curr][i] );
            }
        }

        void dfs(int u, vector<int> &visited) {
            visit(u);
            visited[u] = 1;

            for(int i = 0; i < e[u].size(); i++) 
                if(!visited[ e[u][i] ]) dfs(e[u][i], visited);
        }

        void visit(int x) {
            cout << v[x] << endl;
        }
};

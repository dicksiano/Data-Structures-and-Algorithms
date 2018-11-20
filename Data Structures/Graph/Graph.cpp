#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        Graph(vector<int> v) : v(v) {
            e.assign(v.size(), vector<int>());
        }

        void addEdge(int i, int j) { e[i].push_back(j); }

        void print() {
            for(int i = 0; i < v.size(); i++) {
                cout << std::setw(2) << v[i] << ": ";
                for(int j = 0; j < e[i].size(); j++)
                    cout << std::setw(2) << v[ e[i][j] ] << " ";
                cout << endl;
            }
        }

        void bfs(int i) {
            vector<int> visited(v.size(), 0);
            bfs(i, visited);
        }

    private:
        vector<int> v;
        vector< vector<int> > e;

        void bfs(int u, vector<int> &visited) {
            queue<int> q; q.push(u);

            while(!q.empty()) {
                int curr = q.front(); q.pop();
                cout << v[curr] << endl;
                visited[curr] = 1;

                for(int i = 0; i < e[curr].size(); i++) 
                    if(!visited[ e[curr][i] ]) q.push( e[curr][i] );
            }
        }
};

int main() {
    int arr[] = {1, 5, 10, 15, 20, 25, 30};
    vector<int> v(arr, arr + 7);

    Graph *g = new Graph(v);
    g->addEdge(1, 0); 
    g->addEdge(3, 0); g->addEdge(3, 1); g->addEdge(3, 2); g->addEdge(3, 6);
    g->addEdge(5, 6);
    g->addEdge(6, 2); g->addEdge(6, 4);
    g->print();
    g->bfs(3);

    return 0;
}
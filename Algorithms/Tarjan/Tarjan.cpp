#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        Graph(vector<char> v) : v(v) {
            e.assign(v.size(), vector<int>());
        }

        void addEdge(int i, int j) { e[i].push_back(j); }


        void tarjan() {
            int s = 0;
            int f = 0;

            vector<int> started(v.size(), 0);
            vector<int> finished(v.size(), 0);

            for(int i = 0; i < v.size(); i++)
                if(started[i] == 0) 
                    dfs(i, s, f, started, finished);
        }

    private:
        vector<char> v;
        vector< vector<int> > e;

        void dfs(int u, int &s, int &f, vector<int> &started, vector<int> &finished) {
            started[u] = ++s;

            for(int i = 0; i < e[u].size(); i++) {
                if( isTreeEdge(u, e[u][i], started) ) { 
                    cout << v[u] << " --- T ---> " << v[ e[u][i] ] << endl; 
                    dfs(e[u][i], s, f, started, finished); 
                }
                else if( isBackEdge(u, e[u][i], started, finished) ) 
                    cout << v[u] << " --- B ---> " << v[ e[u][i] ] << endl;
                else if( isForwardEdge(u, e[u][i], started, finished) ) 
                    cout << v[u] << " --- F ---> " << v[ e[u][i] ] << endl;
                else if( isCrossEdge(u, e[u][i], started, finished) ) 
                    cout << v[u] << " --- C ---> " << v[ e[u][i] ] << endl;
            }
            
            finished[u] = ++f;
        }

        bool isTreeEdge(int i, int j, vector<int> started) { return !started[j]; }
        bool isBackEdge(int i, int j, vector<int> started, vector<int> finished)    { return started[i] > started[j] && !finished[j]; }
        bool isForwardEdge(int i, int j, vector<int> started, vector<int> finished) { return started[i] < started[j] &&  finished[j]; }
        bool isCrossEdge(int i, int j, vector<int> started, vector<int> finished)   { return started[i] > started[j] &&  finished[j]; }
        
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

    g->tarjan();

    return 0;
}
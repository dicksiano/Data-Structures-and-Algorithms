#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        Graph(vector<char> v) : v(v) {
            e.assign(v.size(), vector<int>());
        }

        void addEdge(int i, int j) { e[i].push_back(j); }

        void SCC() {
            int s = 0;

            vector<int> started(v.size(), 0);
            vector<int> SCC(v.size(), 0);
            vector<int> isStackMember(v.size(), 0);
            stack<int> P;

            for(int i = 0; i < v.size(); i++)
                if(started[i] == 0) 
                    dfs(i, s, started, SCC, isStackMember, P);
        }

    private:
        vector<char> v;
        vector< vector<int> > e;

        void dfs(int u, int &s, vector<int> &started, vector<int> &SCC, vector<int> &isStackMember, stack<int> &P) {
            started[u] = SCC[u] = ++s;
            isStackMember[u] = 1; P.push(u);

            for(int i = 0; i < e[u].size(); i++) {
                if( started[ e[u][i] ] == 0 ) {
                    dfs(e[u][i], s, started, SCC, isStackMember, P);
                    SCC[u] = min(SCC[u], SCC[ e[u][i] ] );
                } else if( isStackMember[ e[u][i] ] ) 
                    SCC[u] = min(SCC[u], started[ e[u][i] ] );
            }

            if(started[u] == SCC[u]) 
                printSCC(u, isStackMember, P);
        }   

        void printSCC(int u, vector<int> &isStackMember, stack<int> &P) {
            int aux;
            while(1) {
                aux = P.top(); P.pop();
                cout << v[ aux ] << " ";
                isStackMember[ aux ] = 0;
                if( u == aux ) break;
            } 
            cout << endl;
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

    g->SCC();

    return 0;
}
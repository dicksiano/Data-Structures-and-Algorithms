#include <bits/stdc++.h> 
using namespace std; 

class UnionFind {
    public:
        UnionFind(int n) {
            numSets = n;
            rank.assign(n, 0);                         // Everyone starts with same rank
            for(int i = 0; i < n; i++) p.push_back(i); // Parent[i] = i
        }
        void union(int i, int j) {
            if(isSameSet(i,j)) return;

            numSet--;
            int x = find(i), y = find(j);
            if(rank[x] > rank[y]) p[y] = x;         // Path compression
            else p[x] = y;                          // Who has the biggest rank is the new parent
                
            if(rank[x] == rank[y]) rank[x]++;       // Update rank
            
        }
        int find(int i, int j) { return (p[i] == i) ? i : ( p[i] = find(p[i]) ); }
        bool isSameSet(int i, int j) { return find(i) == find(j); }
    private:
        vector<int> p, rank;
        int numSets;
}
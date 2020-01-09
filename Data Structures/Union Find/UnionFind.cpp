#include <bits/stdc++.h> 
using namespace std; 

class UnionFind {
    public:
        UnionFind(int n) {
            numSets = n;
            size.assign(n, 1);                         // Everyone starts with same size
            for(int i = 0; i < n; i++) p.push_back(i); // Parent[i] = i
        }
        void union(int i, int j) {
            if(isSameSet(i,j)) return;

            numSet--;
            int x = find(i), y = find(j);
            int maxi = (size[x] > size[y]) ? x : y; // Path compression
            int mini = (size[x] > size[y]) ? y : x; // Who has the biggest size is the new parent

            p[mini] = maxi;
            size[maxi] = += size[mini];               
        }
        int find(int i, int j) { return (p[i] == i) ? i : ( p[i] = find(p[i]) ); }
        bool isSameSet(int i, int j) { return find(i) == find(j); }
    private:
        vector<int> p, size;
        int numSets;
}
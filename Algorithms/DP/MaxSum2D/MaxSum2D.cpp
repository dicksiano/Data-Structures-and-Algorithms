
#include <bits/stdc++.h> 
using namespace std;

/* 
    Time:  O(n⁴)
    Space: O(1) - DP in place
*/
void preProcess(vector< vector<int> > &M, int m, int n) {
    for(int i = 0; i < m; i++)    
        for(int j = 0; j < n; j++) {
            if(i > 0) M[i][j] += M[i-1][j];             // Upper block
            if(j > 0) M[i][j] += M[i][j-1];             // Left block
            if(i > 0 && j > 0) M[i][j] -= M[i-1][j-1];  // Inclusion - exclusion
        }        
}

int query(vector< vector<int> > M, int a, int b, int c, int d) {
    int res = M[c][d];
    if(a > 0) res -= M[a-1][d];                         // Upper block
    if(b > 0) res -= M[c][b-1];                         // Left block
    if(a > 0 && b > 0) res += M[a-1][b-1];              // Inclusion - exclusion
    return res;
}

int maxSum2D(vector< vector<int> > M, int m, int n) {  // O(n⁴)
    int res = 0;
    for(int a = 0; a < m; a++)
        for(int b = 0; b < n; b++)
            for(int c = a; c < m; c++)
                for(int d = b; d < n; d++)
                    res = max(res, query(M, a,b,c,d));
    return res;
}

int main() {
    vector< vector<int> > M(5);
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            M[i].push_back(10 * i + j);
  
    preProcess(M, 5, 5);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) 
            cout << M[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    cout << maxSum2D(M, 5, 5) << endl;
    return 0;
}
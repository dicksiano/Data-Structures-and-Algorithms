#include <bits/stdc++.h> 
using namespace std; 

/*
    Longest Common Subsequence

    Time:  O(m * n)
    Space: O(m * n)
*/
int lcs(string x, string y) {
    int dp[x.size() + 1][y.size() + 1];

    for(int i = 0; i <= x.size(); i++) dp[i][0] = 0;
    for(int j = 0; j <= y.size(); j++) dp[0][j] = 0;

    for(int i = 1; i <= x.size(); i++) 
        for(int j = 1; j <= y.size(); j++) {
            if(x[i-1] == y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
        }            
    return dp[x.size()][y.size()];
}

int main() {
    string x = "aggfak", y = "gxfxayk";
    cout << lcs(x, y) << endl;
    return 0;
}
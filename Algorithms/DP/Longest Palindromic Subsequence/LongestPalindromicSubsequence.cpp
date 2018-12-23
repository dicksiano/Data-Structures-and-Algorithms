#include <bits/stdc++.h>

using namespace std;

int lps(string s) {
    int N = s.size();
    int dp[N][N] = {};

    for(int i = 0; i < N; i++) dp[i][i] = 1;

    for(int step = 1; step < N; step++)
        for(int i = 0, j = i + step; i < N - step; i++, j++) {
            if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else             dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    return dp[0][N-1];
}

int main() {
    cout << lps("agbdba") << endl;
    return 0;
}
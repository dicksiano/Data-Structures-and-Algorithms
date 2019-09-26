#include <bits/stdc++.h>

using namespace std;

int backtrack(const string &t, const string &p, int i, int j, vector< vector<int> > &dp) {
    if(i >= t.size() && j >= p.size()) return true;
    if(j >= p.size()) return false;

    if(dp[i][j] != -1) return dp[i][j];

    if(j < (p.size()-1) && p[j+1] == '*') {
        if(i < t.size() && (t[i] == p[j] || p[j] == '.'))
            return dp[i][j] = backtrack(t, p, i+1, j, dp) || backtrack(t, p, i, j+2, dp) || backtrack(t, p, i+1, j+2, dp);

        return dp[i][j] = backtrack(t, p, i, j+2, dp);
    } else if(i < t.size() && (t[i] == p[j] || p[j] == '.')) {
        return dp[i][j] = backtrack(t, p, i+1, j+1, dp);
    } else {
        return dp[i][j] = 0;  
    }
}
    
bool regex( const string &text, const string &pattern ) {
    vector< vector<int> > dp(text.size()+1, vector<int>(pattern.size()+1, -1));
    return backtrack(text, pattern, 0, 0, dp);
}
int main() {
    cout << regex("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", "a*b*") << endl;
    cout << regex("aaaaaaaabbbbbbbbbb", "a*b*") << endl;
    cout << regex("aabbc", "a*b*") << endl;
    return 0;
}

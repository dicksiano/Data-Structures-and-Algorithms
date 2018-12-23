#include <bits/stdc++.h>
using namespace std;

#define MAX_INT 99999999

// O(n)
vector<int> preProcess(vector<int> v) { 
    for(int i = 1; i < v.size(); i++) 
        v[i] += v[i-1];
    return v;
}
// O(1)
int sum(vector<int> s, int i, int j) { return s[j] - ((i > 0) ? s[i-1] : 0); }

int obst(vector<int> freq) {
    int N = freq.size();
    int dp[N+1][N+1] = {}, currSum;
    vector<int> s = preProcess(freq); // O(n)

    for(int i = 0; i < N; i++)  dp[i][i+1] = freq[i];
    for(int step = 2; step <= N; step++) 
        for(int i = 0, j = i + step; i <= N - step; i++, j++) {
            dp[i][j] = MAX_INT;
            currSum = sum(s, i, j-1);
            for(int k = i; k < j; k++) 
                dp[i][j] = min(dp[i][j], currSum + dp[i][k] + dp[k+1][j]);
        }
    return dp[0][N];
}

int main() {
    vector<int> freq; freq.push_back(4); freq.push_back(2); freq.push_back(6); freq.push_back(3);
    cout << obst(freq) << endl;
    return 0;
}
#include <bits/stdc++.h> 
using namespace std; 

/*
    Burst Ballon

    Time:  O(n^3)
    Space: O(n^2)
*/
int burstBallon(vector<int> d) {
    int N = d.size();
    int b[N + 2];
    int dp[N+1][N+1] = {};    

    b[0] = b[N + 1] = 1;                        // Important!
    for(int i = 0; i < N; i++) b[i + 1] = d[i];
    for(int i = 0; i < N; i++) dp[i][i+1] = b[i] * b[i+1] * b[i+2];
    
    for(int step = 2; step <= N; step++) 
        for(int i = 0, j = i + step; i <= N - step; i++, j++) 
            for(int k = i; k < j; k++) 
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + b[i] * b[k+1] * b[j+1]); 
    return dp[0][N];
}

int main() {
    int arr[] = {3,1,5,8};
    vector<int> d(arr, arr + 4);
    cout << burstBallon(d) << endl;
    return 0;
}
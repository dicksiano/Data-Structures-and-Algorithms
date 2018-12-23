#include <bits/stdc++.h> 
using namespace std; 

#define MAX_INT 999999999

/*
    Matrix Chain Multiplication

    Time:  O(n^3)
    Space: O(n^2)
*/
int mcm(vector<int> d) {
    int N = d.size() - 1; // N is the number of matrix
    int dp[N][N];

    for(int i = 0; i < N; i++) dp[i][i] = 0;

    for(int step = 1; step < N; step++) {
        for(int i = 0; i < N; i++) {
            dp[i][i + step] = MAX_INT;
            for(int k = i; k < i + step; k++) dp[i][i+step] = min(dp[i][i+step], dp[i][k] + dp[k+1][i+step] + d[i] * d[k+1] * d[i+step+1]);
        } 
    }
    return dp[0][N-1];
}

int main() {
    int arr[] = {5,4,1,3,7,2};
    vector<int> d(arr, arr + 6);
    cout << mcm(d) << endl;
    return 0;
}
#include <bits/stdc++.h> 
using namespace std;

#define MAX 300
int N, dp[MAX][MAX];

int v[] = {3, 34, 4, 12, 5, 2};

/*
    Time:  O(n * k)
    Space: O(n * k)
*/
int subsetSum(int k, int i) {
    if(k == 0) return 1;                         // Completed sum!
    if(k < 0 ) return 0;                         // Passed!
    if(i == N) return 0;                         // Have already seen all elements

    if(dp[k][i] == -1) 
        dp[k][i] = subsetSum(k - v[i] ,i+1) || subsetSum(k, i+1); // Take it or leave it
    return dp[k][i];
}

int main() {
    N = 6;

    memset(dp, -1, sizeof(dp));
    cout << subsetSum(9, 0) << endl;

    memset(dp, -1, sizeof(dp));
    cout << subsetSum(29, 0) << endl;
    return 0;
}
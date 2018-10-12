#include <bits/stdc++.h> 
using namespace std;

#define MAX 300
int N, dp[MAX][MAX];

int weights[] = {10, 20, 30};
int values[] = {60, 101, 130};

/*
    Time: O(wv)
    Space: O(nw)
*/
int knapsack(int w, int i) {
    if(w == 0) return  0;       // No more weight to carry more items
    if(i == N) return 0;        // Have already seen all elements

    if(weights[i] > w)          // Can't carry that item
        return (dp[w][i+1] != -1) ? (dp[w][i+1] = knapsack(w, i + 1)) : dp[w][i+1]; 

    if(dp[w][i] == -1) 
        dp[w][i] = max( knapsack(w, i + 1), values[i] + knapsack(w - weights[i], i+1) ); // Take it or leave it!
    return dp[w][i];
}

int main() {
    memset(dp, -1, sizeof(dp));
    N = 3;
    cout << knapsack(50, 0) << endl;
    return 0;
}
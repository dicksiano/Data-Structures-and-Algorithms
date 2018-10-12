#include <bits/stdc++.h>
using namespace std;

#define INF 2e8

int coinChange(int coins[], int size, int value) {
    if(value == 0) return 0;
    if(value < 0) return INF;

    int dp[value + 1]; 
    dp[0] = 0;
    for(int i = 1; i <= value; i++) {
        dp[i] = INF;
        for(int j = 0; j < size; j++) 
            dp[i] = min(dp[i], coinChange(coins, size, i - coins[j]));
        dp[i]++;
    }
    return dp[value];
}

int main() {
    int coins[] = {1, 3, 4, 5};
    int value = 7;
            
    cout << "coinChange: " << coinChange(coins, 4, value) <<  endl;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
#define INFINITY_INT 999999999

/*
    Time: O(n²k) - each state (n,k) is processed n times
    Space: O(nk)
*/
int eggDrop(int egg, int floors) {
    int dp[egg+1][floors+1]; // (egg, floor)

    for(int i = 1; i <= egg; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1; // There's only one floor, so you only need 1 trial
    }
    for(int i = 1; i <= floors; i++) dp[1][i] = i; // You have only 1 egg, so you must test floor by floor

    for(int i = 2; i <= egg; i++) 
        for( int j = 2; j <= floors; j++) {
            dp[i][j] = INFINITY_INT;
            for(int k = 1; k <= j; k++)
                dp[i][j] = min( dp[i][j], 1 + max(dp[i - 1][k - 1], dp[i][j - k])); // min of 1 + max(egg break, egg doesn't break)
        }
    return dp[egg][floors];
}

int main() {
    int egg, floor;
    cin >> egg >> floor;
    cout << eggDrop(egg, floor) << std::endl;
    return 0;
}
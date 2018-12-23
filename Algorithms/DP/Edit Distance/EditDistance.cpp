#include <bits/stdc++.h> 
using namespace std; 

#define MAX_INT 999999999

/*
    Minimum Edit Distance
    Convert string y to x: y <- x

    Time:  O(n * m)
    Space: O(n * m)
*/
int edit(string x, string y) {
    int dp[y.size() + 1][x.size() + 1];

    for(int j = 0; j <= x.size(); j++) dp[0][j] = j;
    for(int i = 0; i <= y.size(); i++) dp[i][0] = i;

    
    for(int i = 1; i <= y.size(); i++) 
        for(int j = 1; j <= x.size(); j++) {
            if(y[i-1] == x[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min( dp[i-1][j-1], // Replace
                                min( dp[i-1][j],   // Delete in y
                                     dp[i][j-1]    // Delete in x
                                    ));
        }
    return dp[y.size()][x.size()];
}

int main() {
    cout << edit("abcdef","azced") << endl;
    return 0;
}
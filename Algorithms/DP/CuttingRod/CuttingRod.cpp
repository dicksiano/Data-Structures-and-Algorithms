#include <bits/stdc++.h> 
using namespace std; 

/*
    Cutting Rod

    Time:  O(n * k)
    Space: O(k)
*/
int cuttingRod(vector<int> v) {
    vector<int> dp(v.size() + 1, 0);
    for(int i = 1; i <= v.size(); i++) 
        for(int j = 0; j < i; j++) 
            dp[i] = max( dp[i], v[j] + dp[i-j-1] );
    return dp[v.size()];
}

int main() {
    int arr[] = {2,5,7,8};
    vector<int> v(arr, arr + 4);
    cout << cuttingRod(v) << endl;
    return 0;
}
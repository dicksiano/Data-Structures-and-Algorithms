#include <bits/stdc++.h> 
using namespace std; 

/*
    Longest Increase Subsequence

    Time:  O(n²)
    Space: O(n)
*/
int lis(vector<int> v) {
    vector<int> dp(v.size(), 1); int res = 0;
    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < i; j++)
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
                res = max(res, dp[i]);
            }
    return res;
}

int main() {
    int arr[] = {3, 4, -1, 0, 6, 2, 3};
    vector<int> v(arr, arr + 7);
    cout << lis(v) << endl;
    return 0;
}
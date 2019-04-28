#include <bits/stdc++.h>

using namespace std;

bool worldBreak(string s, unordered_set<string> dict) {
    int N = s.size();
    int dp[N]; memset(dp, 0, sizeof(dp));
    string sub = "";

    for(int i = 0; i < s.size(); i++) {
        sub.push_back(s[i]);
        dp[i] = dict.find(sub) != dict.end();

        for(int j = 0; j < i && !dp[i]; j++) 
            if(dp[j]) dp[i] = dp[j] & ( dict.find(&sub[j+1]) != dict.end() );
    }
    return dp[N-1];
 }

int main() {
    unordered_set<string> dict( {"i", "a", "am", "ace"} );
    cout << worldBreak("iamace", dict) << endl;
    return 0;
}

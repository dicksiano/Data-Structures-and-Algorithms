#include <bits/stdc++.h>
using namespace std;

#define PRIME 11
#define MOD 1223

int hash(string s, int len) {
    int h = 0;
    for(int i = 0; i < len; i++) h = (PRIME * (h  + s[i])) % MOD;
    return h;
}

bool naiveMatch(string s, int pos, string p) {
    for(int i = 0; i < p.size(); i++)
        if(p[i] != s[i + pos]) return false;
    return true;
}

int rabinKarp(string s, string p) {
    int hashP = hash(p, p.size()), currentHash = hash(s, p.size()), h = (int) pow(PRIME, p.size());
    for(int i = 0; i < s.size() - p.size(); i++) {
        if(hashP == currentHash)
            if(naiveMatch(s, i, p)) return i;
        currentHash = ( PRIME * (currentHash - s[i] * h + s[i + p.size()]) )%MOD; // Sliding window tecnique
        if(currentHash < 0) currentHash += MOD;
    }
    return -1;
}

int main() {
    string s = "acabaababdababaxyzppacababapq", p = "ababa";
    cout << "RabinKarp(" << s << "," << p << ") = " << rabinKarp(s,p) << endl;
    return 0;
}
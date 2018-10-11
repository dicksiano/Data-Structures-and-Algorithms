#include <bits/stdc++.h>
using namespace std;

#define PRIME 3
#define MOD 1223999

int hash(string s, int len) {
    int h = 0;
    for(int i = 0; i < len; i++) h = (h + int(s[i]) * (int)pow(PRIME, i + 1)) % MOD;
    return (h < 0) ? (h + MOD) : h;
}

bool naiveMatch(string s, int pos, string p) {
    for(int i = 0; i < p.size(); i++)
        if(p[i] != s[i + pos]) return false;
    return true;
}
int rabinKarp(string s, string p) {
    int hashP = hash(p, p.size()), currentHash = hash(s, p.size()), h = (int)pow(PRIME, p.size());
    for(int i = 0; i < s.size() - p.size(); i++) {
        cout << hashP << "," << currentHash << endl;
        if(hashP == currentHash)
            if(naiveMatch(s, i, p)) return i;
        currentHash = ( currentHash / PRIME - int(s[i]) + int(s[ i+p.size() ]) * h)%MOD; // Sliding window tecnique
    }
    return -1;
}

int main() {
    string s = "acabaababdababaxyzppacababapq", p = "ababa";
    cout << "RabinKarp(" << s << "," << p << ") = " << rabinKarp(s,p) << endl;
    return 0;
}
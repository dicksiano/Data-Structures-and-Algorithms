#include <bits/stdc++.h>
using namespace std;

#define PRIME 11
#define MOD 999999999

unsigned long long int hash(string s, int len) {
    unsigned long long int h = 0;
    for(int i = 0; i < len; i++) h += int(s[i]) * (int)pow(PRIME, i + 1);
    return h;
}

bool naiveMatch(string s, int pos, string p) {
    for(int i = 0; i < p.size(); i++)
        if(p[i] != s[i + pos]) return false;
    return true;
}
int rabinKarp(string s, string p) {
    unsigned long long int hashP = hash(p, p.size()), currentHash = hash(s, p.size());
    for(int i = 0; i < s.size() - p.size(); i++) {
        if(hashP == currentHash)
            if(naiveMatch(s, i, p)) return i;
        currentHash = ((currentHash - PRIME * int(s[i])) / PRIME + int(s[ i + p.size() ]) * (int)pow(PRIME, p.size()))%MOD; // Sliding window tecnique
    }
    return -1;
}

int main() {
    string s = "acabaababdababaxyzppacababapq", p = "ababa";
    cout << "RabinKarp(" << s << "," << p << ") = " << rabinKarp(s,p) << endl;
    return 0;
}
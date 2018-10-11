#include <bits/stdc++.h>
using namespace std;

int boyerMoore(string s, string p) {
    vector<int> alphabet(256, -1);
    for(int i = 0; i < p.size(); i++) alphabet[ p[i] ] = i;

    for(int i = p.size(), j = i, k = i; i < s.size(); ) {
        if(s[i] == p[j]) {
            if(j == 0) return i;
            else { i--; j--; }
        } else {
            k = alphabet[ s[i] ];               // Case 1: P doesn't have letter, align p[0] with s[i+1]
            i += p.size() - min(j, 1 + k);      // Case 2: Last ocorrence of the letter is less than j, align the ocorrences
            j = p.size() - 1;                   // Case 3: Last ocorrence of the letter is bigger than j, shift 1 position
        }
    }
    return -1;
}

int main() {
    string s = "acabaababdababaxyzppacababapq", p = "ababa";
    cout << "BoyerMoore(" << s << "," << p << ") = " << boyerMoore(s,p) << endl;
    return 0;
}
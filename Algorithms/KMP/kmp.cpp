#include <bits/stdc++.h>
using namespace std;

/* 
    Time: O(n + m) - preProcess + search
    Space: O(m) - vector F
*/
void preProcess(vector<int> &F, string p) {
    F[0] = -1;                                  // Important step!
    for(int i = 0, j = -1; i < p.size();) {
        while(j >= 0 && p[i] != p[j]) j = F[j];
        F[++i] = ++j;
    }
}

vector<int> kmp(string s, string p) {
    vector<int> F(p.size() + 1, -1), res;
    preProcess(F, p);                           // O(m)

    for(int i = 0, j = 0; i < s.size();) {      // O(n)
        while(j >= 0 && s[i] != p[j]) j = F[j];
        i++; j++;
        if(j == p.size()) {
            res.push_back(i - j);
            j = F[j];
        }
    }
    return res;
}

int main() {
    string s = "acabaababdababaxyzppacababapq", p = "ababa";
    cout << "kmp(" << s << "," << p << ") = ";
    for(int i = 0; i < kmp(s,p).size(); i++) cout << kmp(s,p)[i] << " ";
    cout << endl;
    return 0;
}
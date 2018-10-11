#include <bits/stdc++.h> 
using namespace std; 

#define ALPHABET 26

class Trie {
    public:
        Trie() {
            isEnd = false;
            for(int i = 0; i < ALPHABET; i++)
                children['a' + i] = NULL;
        }
        bool isEnd;
        map<char, Trie *> children;
};

void insert(Trie *p, string s) {
    for(int i = 0; i < s.size(); i++) {
        if(!p->children[s[i]])  p->children[s[i]] = new Trie();
        p = p->children[s[i]];
    }
    p->isEnd = true;
}

bool find(Trie *p, string s) {
    for(int i = 0; i < s.size(); i++) {
        if(!p->children[s[i]]) return false;
        p = p->children[s[i]];
    }
    return p != NULL && p->isEnd; 
}

int main() {
    string s1 = "a", s2 = "these", s3 = "the", s4 = "ball", s5 = "ballon";
    Trie *t = new Trie();
    insert(t, s1);
    insert(t, s2);
    insert(t, s3);
    insert(t, s4);

    cout << "Find(" << s1 << ") = " << find(t, s1) << endl;
    cout << "Find(" << s2 << ") = " << find(t, s2) << endl;
    cout << "Find(" << s3 << ") = " << find(t, s3) << endl;
    cout << "Find(" << s4 << ") = " << find(t, s4) << endl;
    cout << "Find(" << s5 << ") = " << find(t, s5) << endl;
    return 0;
}
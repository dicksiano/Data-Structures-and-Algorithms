#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

/* 
    Build: O(n)
    Query: O(n)
    Update: O(n)
*/
class SegmentTree {
    public:
        SegmentTree(vector<int> v) {
            n = v.size();
            a.assign(4 * n, INF);
            build(v, 1, 0, n-1);
        }
        int query(int i, int j) { return query(i, j, 1, 0, n-1); }
        void update(int i, int x) { update(i, x, 1, 0, n-1); }

    private:
        vector<int> a;
        int n;
        int left(int i) { return i << 1; }
        int right(int i) { return (i << 1) + 1; }
        int mid(int l, int r) { return (l + r) / 2; }

        void build(vector<int> v, int p, int l, int r) {
            if( l == r ) { a[p] = v[l]; return; }

            build(v, left(p), l, mid(l,r));
            build(v, right(p), mid(l,r) + 1, r);
            a[p] = min(a[left(p)], a[right(p)]);
        }

        int query(int i, int j, int p, int l, int r) {
            if(i > r || j < l) return INF;
            if(l >= i && r <= j) return a[p];
            return min(query(i, j, left(p), l, mid(l,r)), query(i, j, right(p), mid(l,r)+1, r));
        }

        void update(int i, int x, int p, int l, int r) {
            if(i < l || i > r) return;
            if(l == r) { a[p] = x; return; }

            update(i, x, left(p), l, mid(l,r));
            update(i, x, right(p), mid(l,r) + 1, r);
            a[p] = min(a[left(p)], a[right(p)]);
        }
};

int main() {
    int arr[7] = {18, 17, 13, 19, 15, 11, 20};
    vector<int> v(arr, arr + 7);

    SegmentTree st(v);
    for(int i = 0; i < v.size(); i++) 
        for(int j = i; j < v.size(); j++)
            cout << "rmq(" << i << "," << j << ") = " << st.query(i,j) << endl;

    st.update(3, -1);

    for(int i = 0; i < v.size(); i++) 
        for(int j = i; j < v.size(); j++)
            cout << "rmq(" << i << "," << j << ") = " << st.query(i,j) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

/* 
    Build:  O(n)
    Query:  O(log n)
    Update: O(log n)
*/  
class SegmentTree {
    public:
        SegmentTree(vector<int> v) {
            n = v.size();
            a.assign(2 * n, 0);
            
            for(int i = 0; i < n; i++) a[i + n] = v[i];
            for(int i = n-1; i > 0; i--) a[i] = a[i * 2] + a[1 + i*2];
        }
        int query(int l, int r) { 
            int q = 0;
            for(l += n, r += n; l <= r; l /= 2, r /= 2) {
			    if(l & 1 ) q += a[l++];
			    if(!(r&1)) q += a[r--];
		    }
            return q;
        }
        void update(int i, int x) { 
            a[i+n] = x;
            for(i = (i+n)/2; i; i /= 2) a[i] = a[i * 2] + a[1 + i*2];
         }
        vector<int> a;

    private:
        int n;
};

int main() {
    int arr[8] = {0, 1, 2, 3 ,4, 5, 6, 7};
    vector<int> v(arr, arr + 8);

    SegmentTree st(v);

    for(int i = 0; i < st.a.size(); i++) cout << st.a[i] << " ";
    cout << endl;
    for(int i = 0; i < v.size(); i++)  {
        cout << endl;
        for(int j = i; j < v.size(); j++)
            cout << "sum(" << i << "," << j << ") = " << st.query(i,j) << " ";
    }

    st.update(3, -1);

    for(int i = 0; i < v.size(); i++) {
        cout << endl;
        for(int j = i; j < v.size(); j++)
            cout << "sum(" << i << "," << j << ") = " << st.query(i,j) <<  " ";
    }

    return 0;
}

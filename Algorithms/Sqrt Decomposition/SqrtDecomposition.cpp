#include <bits/stdc++.h> 
using namespace std; 

/* 
    Time:  O(n) - PreProcess
           O(sqrt n) - Per query
    Space: O(n)
*/
vector<int> preProcess(vector<int> v, int n) {
    int sqrtn = (int)ceil(sqrt(n));
    vector<int> sq(sqrtn, 0);
    for(int i = 0; i < n; i++) sq[i / sqrtn] += v[i];
    return sq;
}

int query(int i, int j, vector<int> v, vector<int> sqrt, int sqrtn) {
    int sum = 0;
    for(; i < j && i % sqrtn != 0; i++) sum += v[i];                // O(log n)
    for(; i + sqrtn <= j; i += sqrtn) sum += sqrt[i / sqrtn];       // O(log n)
    for(; i <= j; i++) sum += v[i];                                 // O(log n)
    return sum;
}

int main() {
    vector<int> v;

    for(int i = 0; i < 16; i++) v.push_back(i);
    vector<int> sqrt = preProcess(v, v.size());
    int sqrtn = sqrt.size();

    for(int i = 0; i < sqrt.size(); i++) cout << "( " << sqrt[i] << " )  ";
    cout << endl << "query(0,3) = " << query(0,3,v,sqrt, sqrtn) << endl;
    cout << "query(4,7) = " << query(4,7,v,sqrt, sqrtn) << endl;
    cout << "query(8,11) = " << query(8,11,v,sqrt, sqrtn) << endl;
    cout << "query(12,15) = " << query(12,15,v,sqrt, sqrtn) << endl;
    cout << "query(2,7) = " << query(2,7,v,sqrt, sqrtn) << endl;
    cout << "query(4,9) = " << query(4,9,v,sqrt, sqrtn) << endl;
    cout << "query(2,9) = " << query(2,9,v,sqrt, sqrtn) << endl;
    cout << "query(5,6) = " << query(5,6,v,sqrt, sqrtn) << endl;
    cout << "query(5,10) = " << query(5,10,v,sqrt, sqrtn) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define NUM_DIGITS 8

void radixsort(vector<int> &v, int base) {
    queue<int> q[base]; 

    for(int d = base; d < (int)pow(base, NUM_DIGITS); d *= base) {
        for(int i = 0; i < v.size(); i++) 
            q[ (v[i] / (d/base) ) % base ].push(v[i]);
        for(int i = 0, j = 0; i < base; i++) 
            while(!q[i].empty()) {
                v[j++] = q[i].front();
                q[i].pop();
            }
    }
}

int main() {
    int arr[] = {54, 23, 557, 2423, 423, 62634, 1,  54 , 23};
    vector<int> v(arr, arr + 9);
    radixsort(v, 10);
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}
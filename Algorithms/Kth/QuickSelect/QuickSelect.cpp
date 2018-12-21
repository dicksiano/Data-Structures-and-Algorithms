#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &v, int a, int b) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int partition(vector<int> &v, int start, int end) {
    int  pivot = start + rand() % (end - start + 1);   // Quick Select
    swap(v, start, pivot);
    pivot = start;
    int l = start + 1, r = end;
    while(l < r) {
        while( l < end && v[l] < v[pivot])  l++;
        while( r > start && v[r] >= v[pivot]) r--;
        if(l < r) swap(v, l, r);
    }
    if(v[pivot] > v[r]) swap(v, pivot, r);
    return r;
}

int quickselect(vector<int> &v, int k, int start, int end) {
    int p = partition(v, start, end);

    if(p == k) return v[p];
    else if(k < p) return quickselect(v, k, start, p - 1);
    else return quickselect(v, k, p + 1, end);
}

int kth(vector<int> v, int k) {
    return quickselect(v, k, 0, v.size() - 1);
}

int main() {
    int arr[] = {34, 56, 23,  43, -34, 23, -2334, 2, -6, 21, 64, 235};
    vector<int> v(arr, arr + 12);
    for(int i = 0; i < v.size(); i++) cout << kth(v, i) << " ";
    cout << endl;
    return 0;
}
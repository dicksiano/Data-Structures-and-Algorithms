#include <bits/stdc++.h>
using namespace std;

int l(int i) { return 1 + (i << 1) ;}
int r(int i) { return 2 + (i << 1) ;}

void swap(vector<int> &v, int a, int b) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
void sift(vector<int> &heap, int i) {
    int maxi = i;
    if(l(i) < heap.size() && heap[l(i)] > heap[maxi]) maxi = l(i);
    if(r(i) < heap.size() && heap[r(i)] > heap[maxi]) maxi = r(i);
    if(i != maxi) { swap(heap, i, maxi); sift(heap, maxi); }
}

void build(vector<int> &v) { for(int i = v.size() / 2; i >= 0; i--) sift(v, i); }

int main() {
    int arr[] = {34, 56, 23,  43, -34, 23, -2334, 2, -6, 21, 64, 235};
    vector<int> v(arr, arr + 12);

    build(v);
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}
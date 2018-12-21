
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &v, int a, int b) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int partition(vector<int> &v, int start, int end, int median) {
    for(int i = start; i <= end; i++) 
        if(v[i] == median ) { median = i; break; }
        
    swap(v, start, median);
    int pivot = start;
    int l = start + 1;
    int r = end;

    while(l < r) {
        while(l < end   && v[l] <  v[pivot]) l++;
        while(r > start && v[r] >= v[pivot]) r--;
        if(l < r) swap(v, l, r);
    }
    if( v[pivot] > v[r] ) swap(v, pivot, r);
    return r;
}

int medianOfFive(vector<int> &v, int i, int j) {
    sort(&v[i], &v[j]);
    return v[ (i + j) / 2];
}

int kth(vector<int> v, int k, int start, int end) {
    if(start == end) return v[start];
    
    int n = end - start + 1;
    int medianSize = (n + 4) / 5;
    vector<int> median(medianSize, 0);

    for(int i = start, j = 0; i <= end; i += 5, j++) 
        median[ j ] = medianOfFive(v, i, min(i + 5, end + 1));

    int medianOfMedian = kth(median, medianSize / 2, 0, medianSize - 1);

    int pivot = partition(v, start, end, medianOfMedian);

    if(pivot == k) return v[pivot];
    if(pivot > k) return kth(v, k, start, pivot - 1);
    return kth(v, k, pivot + 1, end);
}

int main() {
    vector<int> v;
    int size = 22;

    for(int j = 0; j < size; j++) {
        v.clear();
        for(int i = 0; i < size; i++) v.push_back(30 - i);
        cout << "kth( " << j << " ) = " << kth(v, j, 0, size - 1) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int medianOfFive(vector<int> &v, int i, int j) {
    sort(&v[i], &v[j]);
    for(int k = i; k < j; k++) cout << v[k] << " ";
    cout << endl;
    return v[ (i + j) / 2];
}
int kth(vector<int> v, int k, int start, int end) {
    int n = end - start + 1;
    int medianSize = (n + 4) / 5;
    vector<int> median(medianSize, 0);

    for(int i = 0; i < medianSize; i += 5)
        median[ i / 5 ] = medianOfFive(v, i, min(i + 5, end + 1));
    
    int medianOfMedian = kth(median, n / 10, 0, medianSize - 1);
    int pivot = partition(v, start, end, medianOfMedian);
    
    if(pivot == k) return v[pivot];
    if(pivot < k) return kth(v, k, start, pivot - 1);
    return kth(v, k, pivot + 1, end);
}

int main() {
    vector<int> v;
    for(int i = 0; i < 22; i++) {
        v.push_back(22 - i);
        cout << 30-i << " ";
    }
    cout << endl;
    int a = median(v, 1, 0, 21);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
    Time:  O(n log n)
    Space: O(n) - Auxiliar vector 
    
    No recursion!
*/
void merge(vector<int> &v, vector<int> &aux, int start, int m, int end) {
    int i = start, j = m + 1, k = start;
    while(i <= m && j <= end) {
        if(v[i] < v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];
    }
    while(i <= m) aux[k++] = v[i++];
    while(j <= end) aux[k++] = v[j++]; 
    for(int x = start; x <= end; x++) v[x] = aux[x];
}

void mergesort(vector<int> &v, vector<int> &aux, int start, int end) {
    for(int b = 1; b < end; b *= 2)
        for(int p = start; p+b <= end; p += 2 * b) 
            merge(v, aux, p, p + b - 1, min(end, p + 2 * b - 1));
}

void sort(vector<int> &v) {
    vector<int> aux(v.size(), 0);
    mergesort(v, aux, 0, v.size() -1);
}

int main() {
    int arr[] = {34, 56, 23,  43, -34, 23, -2334, 2, -6, 21, 64, 235};
    vector<int> v(arr, arr + 12);
    sort(v);
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}

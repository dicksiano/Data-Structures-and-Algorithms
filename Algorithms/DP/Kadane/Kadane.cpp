#include <bits/stdc++.h> 
using namespace std; 

/*
    Max Sum 1D

    Time:  O(n)
    Space: O(1)
*/
int maxSum1D(vector<int> v, int size) {
    int maxSum = 0, currentSum = 0;
    for(int i = 0; i < size; i++) {
        currentSum += v[i];
        if(currentSum < 0) currentSum = 0;
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    int arr[] = {2, -8, 4, -1, 4, 4, -6, 3, -6};
    vector<int> v(arr, arr + 9) ;
    cout << maxSum1D(v, v.size()) << endl;
}
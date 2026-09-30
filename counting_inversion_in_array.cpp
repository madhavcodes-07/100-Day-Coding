//Problem: Count number of inversions using modified merge sort.
//Inversion if i < j and a[i] > a[j].



//solution:



#include <bits/stdc++.h>
using namespace std;

long long mergeCount(vector<int>& a, vector<int>& tmp, int lo, int hi) {
    if (hi - lo <= 1) return 0;

    int mid = lo + (hi - lo) / 2;
    long long inv = 0;
    inv += mergeCount(a, tmp, lo, mid);
    inv += mergeCount(a, tmp, mid, hi);

    int i = lo, j = mid, k = lo;
    while (i < mid && j < hi) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            inv += mid - i;          // a[j] is smaller than all remaining left elements
        }
    }
    while (i < mid) tmp[k++] = a[i++];
    while (j < hi)  tmp[k++] = a[j++];

    for (int x = lo; x < hi; x++) a[x] = tmp[x];
    return inv;
}

long long countInversions(vector<int> a) {   // passed by value: original stays unsorted
    vector<int> tmp(a.size());
    return mergeCount(a, tmp, 0, (int)a.size());
}

int main() {
    cout << countInversions({2, 4, 1, 3, 5}) << "\n";   // 3
    cout << countInversions({5, 4, 3, 2, 1}) << "\n";   // 10
    cout << countInversions({1, 2, 3, 4, 5}) << "\n";   // 0
    return 0;
}
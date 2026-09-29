//Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
//Distribute into buckets, sort each, concatenate.



//solution:



#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<double>& a) {
    int n = a.size();
    if (n <= 1) return;

    vector<vector<double>> buckets(n);

    // 1. Distribute
    for (double x : a) {
        int idx = (int)(n * x);      // x in [0,1) => idx in [0, n-1]
        buckets[idx].push_back(x);
    }

    // 2. Sort each bucket
    for (auto& b : buckets) sort(b.begin(), b.end());

    // 3. Concatenate
    int k = 0;
    for (auto& b : buckets)
        for (double x : b) a[k++] = x;
}

int main() {
    vector<double> a = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    bucketSort(a);
    for (double x : a) cout << x << " ";
    cout << "\n";
}
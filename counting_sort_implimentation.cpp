//Problem: Sort array of non-negative integers using counting sort.
//Find max, build freq array, compute prefix sums, build output.



//solution:


#include <vector>
#include <algorithm>
using namespace std;

vector<int> countingSort(const vector<int>& arr) {
    if (arr.empty()) return {};

    // 1. Find max
    int mx = *max_element(arr.begin(), arr.end());

    // 2. Build frequency array
    vector<int> freq(mx + 1, 0);
    for (int x : arr) freq[x]++;

    // 3. Prefix sums: freq[v] = number of elements <= v
    for (int v = 1; v <= mx; v++) freq[v] += freq[v - 1];

    // 4. Build output (backwards keeps it stable)
    vector<int> out(arr.size());
    for (int i = (int)arr.size() - 1; i >= 0; i--) {
        out[--freq[arr[i]]] = arr[i];
    }
    return out;
}
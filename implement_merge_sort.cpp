//Problem: Implement Merge Sort - Implement the algorithm.

//Input:
//- First line: integer n
//- Second line: n space-separated integers

//Output:
//- Print the sorted array or search result

//Example:
//Input:
//5
//64 34 25 12 22
//
//Output:
//12 22 25 34 64





//solution:





#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < (int)leftPart.size() && j < (int)rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }

    while (i < (int)leftPart.size()) arr[k++] = leftPart[i++];
    while (j < (int)rightPart.size()) arr[k++] = rightPart[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i + 1 < n ? " " : "\n");
    }

    return 0;
}
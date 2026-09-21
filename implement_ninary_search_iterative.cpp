//Problem: Implement Binary Search Iterative - Implement the algorithm.

//Input:
//- First line: integer n
//- Second line: n space-separated integers

//Output:
//- Print the sorted array or search result

//Example:
//Input:
//5
//64 34 25 12 22

//Output:
//12 22 25 34 64



//solution:




#include <bits/stdc++.h>
using namespace std;

// Iterative binary search: finds the index where `key`
// should be inserted into the sorted range nums[0..hi]
int binarySearchInsertPos(vector<int>& nums, int lo, int hi, int key) {
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] <= key) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return lo; // insertion point
}

void binaryInsertionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int pos = binarySearchInsertPos(nums, 0, i - 1, key);

        // Shift elements from pos to i-1 one step right
        for (int j = i - 1; j >= pos; j--) {
            nums[j + 1] = nums[j];
        }
        nums[pos] = key;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    binaryInsertionSort(nums);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << (i + 1 < n ? " " : "\n");
    }
    return 0;
}
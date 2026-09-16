//Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

//Lower Bound: The index of the first element in the array that is greater than or equal to x.
//Upper Bound: The index of the first element in the array that is strictly greater than x.

//Input:
//- First line: integer n representing the size of the array
//- Second line: n space-separated sorted integers
//- Third line: integer x (the target value)

//Output:
//- Print two integers:
 // 1) Index of the lower bound of x
 // 2) Index of the upper bound of x

//Example:
//Input:
//7
//1 2 4 4 4 5 7
//4

//Output:
//2 5

//Explanation:
//For the given array [1, 2, 4, 4, 4, 5, 7] and x = 4:
// - The lower bound is at index 2, which is the first occurrence of 4.
//- The upper bound is at index 5, which is the first element greater than 4 (i.e., 5).
//Binary Search is used to find both bounds efficiently in O(log n) time.





//solution:




#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int x) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int upperBound(vector<int>& nums, int x) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] <= x) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int x;
    cin >> x;

    cout << lowerBound(nums, x) << " " << upperBound(nums, x) << endl;

    return 0;
}
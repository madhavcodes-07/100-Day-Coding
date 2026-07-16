//Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

//Input:
//- First line: integer n
//- Second line: n integers

//Output:
//- Print the count of subarrays having sum zero

//Example:
//Input:
//6
//1 -1 2 -2 3 -3

//Output:
//6

//Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6. file name with solution


//solution:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Count of each prefix sum seen so far.
    // A prefix sum of 0 (before the array starts) counts as one occurrence,
    // so that subarrays starting at index 0 are counted correctly.
    unordered_map<long long, long long> freq;
    freq[0] = 1;

    long long prefixSum = 0;
    long long count = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += nums[i];

        // If this prefix sum has occurred 'c' times before, it means there are
        // 'c' earlier prefixes equal to the current one, each forming a
        // zero-sum subarray ending at index i.
        auto it = freq.find(prefixSum);
        if (it != freq.end()) {
            count += it->second;
            it->second++;
        } else {
            freq[prefixSum] = 1;
        }
    }

    cout << count << endl;

    return 0;
}
//Problem: Given an array of integers, rotate the array to the right by k positions.

//Input:
//- First line: integer n
//- Second line: n integers
//- Third line: integer k

//Output:
//- Print the rotated array

//Example:
//Input:
//5
//1 2 3 4 5
//2

//Output:
//4 5 1 2 3 


//solution:


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int k;
    cin >> k;
    k = k % n;

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[(i + k) % n] = nums[i];
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
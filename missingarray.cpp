// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer pos (1-based position to delete)

// Output:
// - Print the updated array with (n-1) elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 10 30 40 50

// Explanation: Delete position 2 (element 20), remaining elements shift left

//solution:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

   static int arr[1000000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long totalSum = (long long)(n + 1) * (n + 2) / 2;

    long long arrSum = 0;
    for (int i = 0; i < n; i++) {
        arrSum += arr[i];
    }

    cout << totalSum - arrSum << endl;

    return 0;
}
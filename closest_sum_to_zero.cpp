//Problem: Given an array of integers, find two elements whose sum is closest to zero.

//Input:
//- First line: integer n
//- Second line: n space-separated integers

//Output:
//- Print the pair of elements whose sum is closest to zero

//Example:
//Input:
//5
//1 60 -10 70 -80

//Output:
//-10 1

//Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.


//solution:


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    int bestLeft = 0, bestRight = n - 1;
    long long bestSum = LLONG_MAX; // track closeness using absolute value

    while (left < right) {
        long long sum = (long long)arr[left] + arr[right];

        if (abs(sum) < abs(bestSum)) {
            bestSum = sum;
            bestLeft = left;
            bestRight = right;
        }

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            // sum == 0, can't get closer than this
            break;
        }
    }

    cout << arr[bestLeft] << " " << arr[bestRight] << endl;

    return 0;
}
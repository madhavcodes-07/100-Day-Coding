//Problem: Implement Selection Sort - Implement the algorithm.

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

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
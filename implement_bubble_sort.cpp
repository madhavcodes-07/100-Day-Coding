//Problem: Implement Bubble Sort - Implement the algorithm.

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




#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no swaps happened, array is already sorted
        if (!swapped) break;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
//Problem: Sort an array using insertion sort.
//Stable sort. Good for nearly sorted arrays.


//solution:



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> insertionSort(vector<int>& arr) {
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }

        return arr;
    }
};

int main() {
    vector<int> arr = {4, 2, 1, 3};

    Solution sol;
    vector<int> result = sol.insertionSort(arr);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
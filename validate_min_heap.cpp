//Problem Statement:
//Check whether a given binary tree satisfies the Min-Heap property.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal

//Output Format:
//- Print YES if valid Min-Heap, otherwise NO

//Example:
//Input:
// 7
//1 3 5 7 9 8 10

//Output:
//YES

//Explanation:
//Each parent node must be smaller than its children.




//solution:



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    bool isMinHeap = true;
    
    // Only internal nodes (those with at least one child) need checking.
    // A node at index i has a left child if 2*i+1 < n.
    for (int i = 0; i < n; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[i] > arr[left]) {
            isMinHeap = false;
            break;
        }
        if (right < n && arr[i] > arr[right]) {
            isMinHeap = false;
            break;
        }
    }
    
    cout << (isMinHeap ? "YES" : "NO") << endl;
    
    return 0;
}
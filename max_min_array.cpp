//Problem: Write a program to find the maximum and minimum values present in a given array of integers.

//Input:
//- First line: integer n
//- Second line: n integers

//Output:
//- Print the maximum and minimum elements

//Example:
//Input:
//6
//3 5 1 9 2 8

//Output:
//Max: 9
//Min: 1 


//solution:


#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    int maxVal = INT_MIN, minVal = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
    }
    
    cout << "Max: " << maxVal << endl;
    cout << "Min: " << minVal << endl;
    
    return 0;
}
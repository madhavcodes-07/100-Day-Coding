//Problem: Write a C program to insert an element x at a given 
//1-based position pos in an array of n integers. Shift existing elements to the right to make space.

/*
Input:
 First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[101];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int pos, x;
    cin >> pos >> x;

    // Shift elements to the right
    for (int i = n; i >= pos; i--)
        a[i] = a[i - 1];

    // Insert element
    a[pos - 1] = x;

    // Print result
    for (int i = 0; i <= n; i++) {
        cout << a[i];
        if (i < n) cout << " ";
    }

    return 0;
}
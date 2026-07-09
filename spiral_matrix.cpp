//Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

//Input:
//- First line: two integers r and c representing the number of rows and columns
//- Next r lines: c integers each representing the matrix elements

//Output:
//- Print all visited elements in the order of traversal, separated by spaces

//Example:
//Input:
//3 3
//1 2 3
//4 5 6
//7 8 9

//Output:
//1 2 3 6 9 8 7 4 5

//Explanation:
//The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

//Test Cases:

//Test Case 1:
//Input:
//2 3
//1 2 3
//4 5 6
//Output:
//1 2 3 6 5 4

//Test Case 2:
//Input:
//3 1
//7
//8
//9
//Output:
//7 8 9 


//solution:

#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int r, c;
    cin >> r >> c;
 
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }
 
    vector<int> result;
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
 
    while (top <= bottom && left <= right) {
        // Left to right along the top row
        for (int j = left; j <= right; j++) {
            result.push_back(matrix[top][j]);
        }
        top++;
 
        // Top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
 
        // Right to left along the bottom row (only if a row remains)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
        }
 
        // Bottom to top along the left column (only if a column remains)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
 
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i + 1 < result.size()) cout << " ";
    }
    cout << endl;
 
    return 0;
}
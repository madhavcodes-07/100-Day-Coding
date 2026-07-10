//Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

//Input:
//- First line: integer n representing number of rows and columns
//- Next n lines: n integers each representing the matrix elements

//Output:
//- Print "Identity Matrix" if the matrix satisfies the condition
//- Otherwise, print "Not an Identity Matrix"

//Example:
//Input:
//3
//1 0 0
//0 1 0
//0 0 1

//Output:
//Identity Matrix file name with solution c++


//solution:







#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int mat[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    bool isIdentity = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && mat[i][j] != 1) {
                isIdentity = false;
            }
            if (i != j && mat[i][j] != 0) {
                isIdentity = false;
            }
        }
    }

    if (isIdentity)
        cout << "Identity Matrix" << endl;
    else
        cout << "Not an Identity Matrix" << endl;

    return 0;
}
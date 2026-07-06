//Problem: Read a string and check if it is a palindrome using two-pointer comparison.

//Input:
//- Single line: string s

//Output:
//- Print YES if palindrome, otherwise NO

//Example:
//Input:
//level

//Output:
//YES

//Explanation: String reads same forwards and backwards


//solution:

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            cout << "NO";
            return 0;
        }
        left++;
        right--;
    }

    cout << "YES";
    return 0;
}
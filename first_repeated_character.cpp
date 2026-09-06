//Problem Statement
//Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

//Input Format
//A single string s.

//Output Format
//Print the first repeated character. If no character is repeated, print -1.

//Sample Input
//  geeksforgeeks

//Sample Output
//  e



#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_set<char> seen;
    char result = 0;
    bool found = false;

    for (char c : s) {
        if (seen.count(c)) {
            result = c;
            found = true;
            break; // first character whose 2nd occurrence appears earliest
        }
        seen.insert(c);
    }

    if (found) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
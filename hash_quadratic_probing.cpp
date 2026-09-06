//Problem Statement
//Implement a hash table using quadratic probing with formula:

//h(k, i) = (h(k) + i*i) % m

//Input Format
//Same as previous.

//Output Format
//Result of SEARCH operations.

//Sample Input
//7
//4
//INSERT 49
//INSERT 56
//SEARCH 49
//SEARCH 15

//Sample Output
//FOUND
//NOT FOUND

//Explanation
//Collisions resolved using i² jumps.



//solution:


#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;       // table size
    cin >> m;

    int q;       // number of operations
    cin >> q;

    vector<int> table(m, -1); // -1 = empty slot
    const int EMPTY = -1;

    for (int op = 0; op < q; op++) {
        string cmd;
        int key;
        cin >> cmd >> key;

        int h = key % m;

        if (cmd == "INSERT") {
            for (int i = 0; i < m; i++) {
                int idx = ((h + i * i) % m + m) % m; // safe mod
                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
                // If slot is already occupied by the same key, no need to reinsert
                if (table[idx] == key) break;
                // If table is full and no slot found after m tries, insertion fails silently
            }
        } 
        else if (cmd == "SEARCH") {
            bool found = false;
            for (int i = 0; i < m; i++) {
                int idx = ((h + i * i) % m + m) % m;
                if (table[idx] == key) {
                    found = true;
                    break;
                }
                if (table[idx] == EMPTY) {
                    // Standard quadratic probing convention: an empty slot
                    // means the key was never inserted along this probe sequence
                    break;
                }
            }
            cout << (found ? "FOUND" : "NOT FOUND") << endl;
        }
    }

    return 0;
}
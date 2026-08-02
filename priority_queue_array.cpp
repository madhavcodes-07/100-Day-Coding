//Problem Statement:
//Implement a Priority Queue using an array. An element with smaller value has higher priority.

//Supported Operations:
//- insert x
//- delete
//- peek

//Input Format:
//- First line contains integer N
//- Next N lines contain operations

//Output Format:
//- Print the deleted or peeked element
//- Print -1 if the queue is empty

//Example:
//Input:
//5
//insert 30
//insert 10
//insert 20
//delete
//peek

//Output:
//10
//20



//solution:


#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
private:
    vector<int> arr;

public:
    void insert(int x) {
        arr.push_back(x);
    }

    int findMinIndex() {
        if (arr.empty()) return -1;
        int minIdx = 0;
        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] < arr[minIdx]) {
                minIdx = i;
            }
        }
        return minIdx;
    }

    int deleteMin() {
        int idx = findMinIndex();
        if (idx == -1) return -1;
        int val = arr[idx];
        arr.erase(arr.begin() + idx);
        return val;
    }

    int peek() {
        int idx = findMinIndex();
        if (idx == -1) return -1;
        return arr[idx];
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    PriorityQueue pq;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string op;
        ss >> op;

        if (op == "insert") {
            int x;
            ss >> x;
            pq.insert(x);
        } else if (op == "delete") {
            cout << pq.deleteMin() << "\n";
        } else if (op == "peek") {
            cout << pq.peek() << "\n";
        }
    }

    return 0;
}
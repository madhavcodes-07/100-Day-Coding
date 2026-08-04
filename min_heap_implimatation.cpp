//Problem Statement:
//Implement a Min Heap using an array where the smallest element is always at the root.

//Supported Operations:
//- insert x
//- extractMin
//- peek

//Input Format:
//- First line contains integer N
//- Next N lines contain heap operations

//Output Format:
//- Print results of extractMin and peek
//- Print -1 if operation cannot be performed

//Example:
//Input:
//6
//insert 40
//insert 10
//insert 30
//peek
//extractMin
//peek

//Output:
//10
//10
//30


//solution:



#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] <= heap[i]) break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if (left < n && heap[left] < heap[smallest]) smallest = left;
            if (right < n && heap[right] < heap[smallest]) smallest = right;
            if (smallest == i) break;
            swap(heap[smallest], heap[i]);
            i = smallest;
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) return -1;
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return minVal;
    }

    int peek() {
        if (heap.empty()) return -1;
        return heap[0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    MinHeap h;
    string line;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "insert") {
            int x;
            ss >> x;
            h.insert(x);
        } else if (cmd == "extractMin") {
            cout << h.extractMin() << "\n";
        } else if (cmd == "peek") {
            cout << h.peek() << "\n";
        }
    }

    return 0;
}
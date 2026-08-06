//Problem Statement:
//Implement a Queue using a linked list supporting enqueue and dequeue operations.

//Input Format:
//- First line contains integer N
//- Next N lines contain queue operations

//Output Format:
//- Print dequeued elements
//- Print -1 if dequeue is attempted on an empty queue


//solution:


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return val;
    }
};

int main() {
    int n;
    cin >> n;
    Queue q;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (type == 2) {
            cout << q.dequeue() << "\n";
        }
    }

    return 0;
}
//Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

//Input:
//- First line: integer n (number of elements)
//- Second line: n space-separated integers

//Output:
//- Print queue elements from front to rear, space-separated

//Example:
//Input:
//5
//10 20 30 40 50

//Output:
//10 20 30 40 50

//Explanation:
//Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.



//solution:


#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Queue implemented using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue: insert at rear
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue: remove from front
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        if (front == nullptr) rear = nullptr; // queue became empty
        delete temp;
        return value;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    // Display elements from front to rear
    void display() {
        Node* current = front;
        bool first = true;
        while (current != nullptr) {
            if (!first) cout << " ";
            cout << current->data;
            first = false;
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free all remaining nodes
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    int n;
    cin >> n;

    Queue q;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.enqueue(val);
    }

    q.display();

    return 0;
}
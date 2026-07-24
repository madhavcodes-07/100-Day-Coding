//Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

//Input:
//- First line: integer n
//- Second line: n space-separated integers

//Output:
//- Print the circular linked list elements starting from head, space-separated

//Example:
//Input:
//5
//10 20 30 40 50

//Output:
//10 20 30 40 50

//Explanation:
//Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.


//solution:



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head = nullptr;

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head; // points to itself
            return;
        }
        // find the last node (the one whose next is head)
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void traverse() {
        if (!head) return;
        Node* temp = head;
        bool first = true;
        do {
            if (!first) cout << " ";
            cout << temp->data;
            first = false;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    CircularLinkedList list;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }

    list.traverse();

    return 0;
}
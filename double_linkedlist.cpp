//Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

//Input:
//- First line: integer n
//- Second line: n space-separated integers

//Output:
//- Print the linked list elements in forward order, space-separated

//Example:
//Input:
//5
//10 20 30 40 50

//Output:
//10 20 30 40 50

//Explanation:
//Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.


//solution:




#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " ";
        temp = temp->next;
    }

    return 0;
}
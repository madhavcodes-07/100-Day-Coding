```
//Problem: Create and Traverse Singly Linked List

//Input:
//- First line: integer n
//- Second line: n space-separated integers

//Output:
//- Print the result

//Example:
//Input:
//5
//10 20 30 40 50

//Output:
//10 20 30 40 50



//solution:



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        head = insertAtEnd(head, val);
    }

    traverse(head);
    deleteList(head);

    return 0;
}
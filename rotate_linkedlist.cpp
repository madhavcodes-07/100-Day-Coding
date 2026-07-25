//Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

//Input:
//- First line: integer n
//- Second line: n space-separated integers
//- Third line: integer k

//Output:
// Print the linked list elements after rotation, space-separated

//Example:
//Input:
//5
//10 20 30 40 50
//2

//Output:
//40 50 10 20 30

//Explanation:
//Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.


//solution:



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head = nullptr;

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void rotateRight(int k) {
        if (!head || !head->next || k == 0) return;

        // Find length and tail
        int n = 1;
        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k = k % n;
        if (k == 0) return;

        // Make it circular
        tail->next = head;

        // Traverse to the (n - k)th node (new tail)
        int stepsToNewTail = n - k;
        Node* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // New head is right after new tail
        head = newTail->next;
        newTail->next = nullptr; // break the circle
    }

    void print() {
        Node* temp = head;
        bool first = true;
        while (temp) {
            if (!first) cout << " ";
            cout << temp->data;
            first = false;
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList list;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }

    int k;
    cin >> k;

    list.rotateRight(k);
    list.print();

    return 0;
}
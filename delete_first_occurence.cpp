//Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

//Input:
//- First line: integer n
//- Second line: n space-separated integers
//- Third line: integer key

//Output:
//- Print the linked list elements after deletion, space-separated

//Example:
//Input:
//5
//10 20 30 40 50
//30

//Output:
//10 20 40 50

//Explanation:
//Traverse list, find first node with key, remove it by adjusting previous node's next pointer.


//solution:

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Add a new node with value val at the end
    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    // Delete the first node whose data matches key
    void deleteKey(int key) {
        if (head == NULL) return;

        // key is at the head
        if (head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        // search for key in rest of list
        Node* prev = head;
        Node* curr = head->next;

        while (curr != NULL) {
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return; // stop after first match
            }
            prev = curr;
            curr = curr->next;
        }
        // key not found, list stays unchanged
    }

    // Print all elements space-separated
    void display() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data;
            if (curr->next != NULL) cout << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Clean up memory
    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
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

    int key;
    cin >> key;

    list.deleteKey(key);
    list.display();

    return 0;
}
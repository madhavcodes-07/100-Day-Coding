//Problem: Count Nodes in Linked List

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

    list.print();

    return 0;
}
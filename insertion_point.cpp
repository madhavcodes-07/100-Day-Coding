//Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

//Input:
//- First line: integer n
//- Second line: n space-separated integers (first list)
//- Third line: integer m
//- Fourth line: m space-separated integers (second list)

//Output:
//- Print value of intersection node or 'No Intersection'

//Example:
//Input:
//5
//10 20 30 40 50
//4
//15 25 30 40 50

//Output:
//30

//Explanation:
//Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.



//solution:



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* createList(int n) {
    if (n == 0) return NULL;

    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }
    return head;
}

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

int findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    while (head1 && head2) {
        if (head1->data == head2->data)
            return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n;
    Node* head1 = createList(n);

    cin >> m;
    Node* head2 = createList(m);

    int ans = findIntersection(head1, head2);

    if (ans == -1)
        cout << "No Intersection";
    else
        cout << ans;

    return 0;
}
//Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

//Input:
//- First line: integer n
//- Second line: n space-separated integers (first list)
//- Third line: integer m
//- Fourth line: m space-separated integers (second list)

//Output:
// - Print the merged linked list elements, space-separated

//Example:
//Input:
//5
//10 20 30 40 50
//4
//15 25 35 45

//Output:
//10 15 20 25 30 35 40 45 50

//Explanation:
//Compare nodes of both lists, append smaller to result, continue until all nodes are merged.


//solution:

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end of a list (for building input lists)
void insertEnd(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    tail->next = (l1 != NULL) ? l1 : l2;

    return dummy.next;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    int first = 1;
    while (temp != NULL) {
        if (!first) printf(" ");
        printf("%d", temp->data);
        first = 0;
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, m, val;

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&list1, val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        insertEnd(&list2, val);
    }

    struct Node* merged = mergeLists(list1, list2);
    printList(merged);

    freeList(merged); // frees all nodes since lists are now linked together

    return 0;
}
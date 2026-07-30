//Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

//Input:
//- Postfix expression with operands and operators

//Output:
//- Print the integer result

//Example:
//Input:
//2 3 1 * + 9 -

//Output:
//-4

//Explanation:
//Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.



//solution:



// postfix_eval.cpp
#include <iostream>
#include <sstream>
using namespace std;

// Node for linked list stack
struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = top;
    top = n;
}

int pop() {
    int val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

int main() {
    string expr, token;
    getline(cin, expr);
    stringstream ss(expr);

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = pop();
            int a = pop();
            if (token == "+") push(a + b);
            else if (token == "-") push(a - b);
            else if (token == "*") push(a * b);
            else push(a / b);
        } else {
            push(stoi(token));
        }
    }

    cout << pop() << endl;
    return 0;
}
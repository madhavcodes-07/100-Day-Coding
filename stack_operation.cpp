//Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

//Input:
//- First line: integer n (number of operations)
//- Next n lines: operation type and value (if applicable)
  //- 1 value: push value
  //- 2: pop
  //- 3: display

//Output:
//- For display: print stack elements from top to bottom
//- For pop: print popped element or 'Stack Underflow'

//Example:
//Input:
//5
//1 10
//1 20
//3
//2
//3

//Output:
//20 10
//20
//10


//solution:


#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    int arr[10005];
    int top;
    int capacity;

public:
    Stack(int cap = 10005) {
        top = -1;
        capacity = cap;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << arr[top--] << endl;
    }

    void display() {
        if (top == -1) {
            cout << endl; // empty stack, nothing to print
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
            if (i != 0) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Stack st;

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int value;
            cin >> value;
            st.push(value);
        } else if (op == 2) {
            st.pop();
        } else if (op == 3) {
            st.display();
        }
    }

    return 0;
}
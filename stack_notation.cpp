//Problem: Convert an infix expression to postfix notation using stack.

//Input:
//- Single line: infix expression (operands are single characters)

//Output:
//- Print the postfix expression

//Example:
//Input:
//A+B*C

//Output:
//ABC*+

//Explanation:
//Operator precedence: * > +
//Use stack to handle operator precedence and associativity


//solution:


#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix, postfix = "";
    cin >> infix;

    stack<char> st;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << postfix;

    return 0;
}
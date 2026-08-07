//Problem Statement:
//Given a queue of integers, reverse the queue using a stack.

//Input Format:
//- First line contains integer N
//- Second line contains N space-separated integers

//Output Format:
//- Print the reversed queue

//Example:
//Input:
//5
//10 20 30 40 50

//Output:
//50 40 30 20 10



//solution:



#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
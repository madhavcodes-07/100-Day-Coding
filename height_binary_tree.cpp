//Problem Statement:
//Find the height (maximum depth) of a given binary tree.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal (-1 represents NULL)

//Output Format:
//- Print the height of the tree

//Example:
//Input:
//7
//1 2 3 4 5 -1 -1

//Output:
//3


//solution:


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    int n = arr.size();

    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (i < n) {
            if (arr[i] != -1) {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;
        }

        // Right child
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
    }

    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = buildTree(arr);
    cout << maxDepth(root) << endl;

    return 0;
}
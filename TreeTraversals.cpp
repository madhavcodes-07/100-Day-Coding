//Problem Statement:
//Perform inorder, preorder, and postorder traversals of a given binary tree.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal (-1 represents NULL)

//Output Format:
//- Print inorder, preorder, and postorder traversals

//Example:
//Input:
//7
//1 2 3 4 5 6 7
//
//Output:
//4 2 5 1 6 3 7
//1 2 4 5 3 6 7
//4 5 2 6 7 3 1




//solution:



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Build tree from level-order array (-1 = NULL)
Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)arr.size()) {
        Node* curr = q.front(); q.pop();

        // left child
        if (i < (int)arr.size()) {
            if (arr[i] != -1) {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;
        }
        // right child
        if (i < (int)arr.size()) {
            if (arr[i] != -1) {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    return root;
}

void inorder(Node* root, vector<int>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->data);
    inorder(root->right, out);
}

void preorder(Node* root, vector<int>& out) {
    if (!root) return;
    out.push_back(root->data);
    preorder(root->left, out);
    preorder(root->right, out);
}

void postorder(Node* root, vector<int>& out) {
    if (!root) return;
    postorder(root->left, out);
    postorder(root->right, out);
    out.push_back(root->data);
}

void printVec(vector<int>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i != (int)v.size() - 1) cout << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildTree(arr);

    vector<int> in, pre, post;
    inorder(root, in);
    preorder(root, pre);
    postorder(root, post);

    printVec(in);
    printVec(pre);
    printVec(post);

    return 0;
}
//Problem Statement:
//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

//Input Format:
//- First line contains integer N
//- Second line contains N space-separated integers
//- Third line contains two node values

// Output Format:
//- Print the LCA value

//Example:
//Input:
//7
//6 2 8 0 4 7 9
//2 8

//Output:
//6


//solution:


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

int lowestCommonAncestor(Node* root, int p, int q) {
    Node* curr = root;
    while (curr) {
        if (p < curr->val && q < curr->val) {
            curr = curr->left;
        } else if (p > curr->val && q > curr->val) {
            curr = curr->right;
        } else {
            return curr->val;
        }
    }
    return -1; // shouldn't happen given constraints
}

int main() {
    int n;
    cin >> n;
    
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    
    int p, q;
    cin >> p >> q;
    
    cout << lowestCommonAncestor(root, p, q) << endl;
    
    return 0;
}
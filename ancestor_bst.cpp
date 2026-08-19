//Problem Statement:
//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

//Input Format:
//- First line contains integer N
//- Second line contains N space-separated integers
//- Third line contains two node values

//Output Format:
// - Print the LCA value

//Example:
//Input:
//7
//6 2 8 0 4 7 9
//2 8

//Output:
//6


//Explanation:



#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    while (root) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root; // split point (or one of p/q equals root->val)
    }
    return nullptr;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> values(n);
    for (int i = 0; i < n; i++) cin >> values[i];
    
    TreeNode* root = nullptr;
    for (int v : values) root = insertIntoBST(root, v);
    
    int p, q;
    cin >> p >> q;
    
    TreeNode* ancestor = lowestCommonAncestor(root, p, q);
    cout << ancestor->val << endl;
    
    return 0;
}
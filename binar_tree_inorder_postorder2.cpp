//Problem Statement:
//Construct a binary tree from given inorder and postorder traversal arrays.

//Input Format:
//- First line contains integer N
//- Second line contains inorder traversal
//- Third line contains postorder traversal

//Output Format:
//- Print preorder traversal of constructed tree

//Example:
//Input:
//5
//4 2 5 1 3
//4 5 2 3 1

//Output:
//1 2 4 5 3

//Explanation:
//Postorder gives root at end, inorder divides left and right subtrees.



//solution:

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

unordered_map<int,int> inIndex;
vector<int> post;
int postIdx;

TreeNode* build(int inLeft, int inRight) {
    if (inLeft > inRight) return nullptr;
    int rootVal = post[postIdx--];
    TreeNode* root = new TreeNode(rootVal);
    int mid = inIndex[rootVal];
    root->right = build(mid + 1, inRight);   // build right first (postorder consumed from back)
    root->left = build(inLeft, mid - 1);
    return root;
}

void preorder(TreeNode* node, vector<int>& out) {
    if (!node) return;
    out.push_back(node->val);
    preorder(node->left, out);
    preorder(node->right, out);
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    post = postorder;
    postIdx = n - 1;
    for (int i = 0; i < n; i++) inIndex[inorder[i]] = i;

    TreeNode* root = build(0, n - 1);

    vector<int> result;
    preorder(root, result);

    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i + 1 < (int)result.size()) cout << " ";
    }
    cout << endl;

    return 0;
}
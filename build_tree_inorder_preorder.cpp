//Problem Statement:
//Construct a binary tree from given preorder and inorder traversal arrays.

//Input Format:
//- First line contains integer N
//- Second line contains preorder traversal
//- Third line contains inorder traversal

//Output Format:
//- Print postorder traversal of constructed tree

//Example:
//Input:
//5
//1 2 4 5 3
//4 2 5 1 3

//Output:
//4 5 2 3 1

//Explanation:
//Preorder identifies root, inorder splits left and right subtrees.



//solution:


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

unordered_map<int, int> idxMap;
vector<int> preorder;
int preIdx;

Node* buildTree(int inLeft, int inRight) {
    if (inLeft > inRight) return nullptr;

    int rootVal = preorder[preIdx++];
    Node* root = new Node(rootVal);

    int mid = idxMap[rootVal];

    root->left = buildTree(inLeft, mid - 1);
    root->right = buildTree(mid + 1, inRight);

    return root;
}

void postorder(Node* node, vector<int>& result) {
    if (!node) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    preorder.resize(n);
    vector<int> inorder(n);

    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    for (int i = 0; i < n; i++) idxMap[inorder[i]] = i;

    preIdx = 0;
    Node* root = buildTree(0, n - 1);

    vector<int> result;
    postorder(root, result);

    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i != (int)result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
//Problem Statement:
//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal (-1 represents NULL)
//- Third line contains two node values

//Output Format:
//- Print the LCA value

//Example:
//Input:
//7
//1 2 3 4 5 6 7
//4 5

//Output:
//2


//solution:



#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build tree from level-order array where -1 represents NULL
TreeNode* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    int n = arr.size();

    while (!q.empty() && i < n) {
        TreeNode* curr = q.front();
        q.pop();

        // left child
        if (i < n) {
            if (arr[i] != -1) {
                curr->left = new TreeNode(arr[i]);
                q.push(curr->left);
            }
            i++;
        }

        // right child
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = new TreeNode(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
    }

    return root;
}

// Standard LCA using node values
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root == nullptr || root->val == p || root->val == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
        return root;
    }
    return left ? left : right;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int p, q;
    cin >> p >> q;

    TreeNode* root = buildTree(arr);

    TreeNode* ans = lowestCommonAncestor(root, p, q);

    if (ans != nullptr) {
        cout << ans->val << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
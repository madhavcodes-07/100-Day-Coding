//Problem Statement:
//Check whether a given binary tree is symmetric around its center.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal (-1 indicates NULL)

//Output Format:
//- Print YES if symmetric, otherwise NO

//Example:
//Input:
//7
//1 2 2 3 4 4 3
//
//Output:
//YES

//Explanation:
//Left subtree is a mirror image of the right subtree.



//solution:




#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build tree from level-order array where -1 denotes NULL
TreeNode* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < (int)vals.size()) {
        TreeNode* curr = q.front(); q.pop();
        
        // left child
        if (i < (int)vals.size()) {
            if (vals[i] != -1) {
                curr->left = new TreeNode(vals[i]);
                q.push(curr->left);
            }
            i++;
        }
        
        // right child
        if (i < (int)vals.size()) {
            if (vals[i] != -1) {
                curr->right = new TreeNode(vals[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    
    return root;
}

bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val)
        && isMirror(t1->left, t2->right)
        && isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    
    TreeNode* root = buildTree(vals);
    
    cout << (isSymmetric(root) ? "YES" : "NO") << endl;
    
    return 0;
}
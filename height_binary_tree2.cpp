//Problem: Height of Binary Tree

//Implement the solution for this problem.

//Input:
//- Input specifications

//Output:
//- Output specifications


//solution:


class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};
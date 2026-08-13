//Problem: Count Leaf Nodes

//Implement the solution for this problem.

//Input:
//- Input specifications

//Output:
//- Output specifications


//solution:

class Solution {
public:
    int countLeafNodes(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
};
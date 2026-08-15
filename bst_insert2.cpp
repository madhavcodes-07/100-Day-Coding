//Problem: BST Search

//Implement the solution for this problem.

//Input:
//- Input specifications

//Output:
//- Output specifications


//solution:


#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};

int main() {
    // quick manual test: build 4 -> (2 -> 1,3), 7
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(2, n1, n3);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* root = new TreeNode(4, n2, n7);

    Solution sol;
    TreeNode* result = sol.searchBST(root, 2);
    if (result) cout << "Found: " << result->val << endl;
    else cout << "Not found" << endl;

    return 0;
}
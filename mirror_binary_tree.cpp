//Problem Statement:
//Convert a binary tree into its mirror image by swapping left and right children at every node.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal (-1 indicates NULL)

//Output Format:
//- Print inorder traversal of mirrored tree

//Example:
//Input:
//7
//1 2 3 4 5 6 7

//Output:
//7 3 6 1 5 2 4

//Explanation:
//Each node’s left and right children are swapped recursively.



//solution:



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Build tree from level-order input where -1 means NULL
Node* buildTree(vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;
    
    Node* root = new Node(values[0]);
    queue<Node*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < values.size()) {
        Node* curr = q.front();
        q.pop();
        
        // Left child
        if (i < values.size()) {
            if (values[i] != -1) {
                curr->left = new Node(values[i]);
                q.push(curr->left);
            }
            i++;
        }
        
        // Right child
        if (i < values.size()) {
            if (values[i] != -1) {
                curr->right = new Node(values[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    
    return root;
}

// Swap left and right children at every node
void mirror(Node* root) {
    if (root == nullptr) return;
    
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(Node* root, vector<int>& result) {
    if (root == nullptr) return;
    
    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    Node* root = buildTree(values);
    mirror(root);
    
    vector<int> result;
    inorder(root, result);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
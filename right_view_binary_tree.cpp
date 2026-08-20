//Problem Statement:
//Print the nodes visible when the binary tree is viewed from the right side.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal (-1 indicates NULL)

//Output Format:
//- Print right view nodes

//Example:
//Input:
//7
//1 2 3 4 5 -1 6

//Output:
//1 3 6

//Explanation:
//At each level, the rightmost node is visible from the right view.



//solution:




#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build tree from level-order input where -1 denotes NULL
Node* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;
    
    Node* root = new Node(vals[0]);
    queue<Node*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        Node* curr = q.front();
        q.pop();
        
        // left child
        if (i < vals.size()) {
            if (vals[i] != -1) {
                curr->left = new Node(vals[i]);
                q.push(curr->left);
            }
            i++;
        }
        
        // right child
        if (i < vals.size()) {
            if (vals[i] != -1) {
                curr->right = new Node(vals[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    
    return root;
}

vector<int> rightSideView(Node* root) {
    vector<int> result;
    if (!root) return result;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            
            if (i == levelSize - 1) {
                result.push_back(node->val);
            }
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    
    Node* root = buildTree(vals);
    vector<int> result = rightSideView(root);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
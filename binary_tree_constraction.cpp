//Problem Statement:
//Construct a Binary Tree from the given level-order traversal.

//Input Format:
//- First line contains integer N
//- Second line contains N space-separated integers (-1 represents NULL)

//Output Format:
//- Print inorder traversal of the constructed tree

//Example:
//Input:
//7
//1 2 3 4 5 -1 6
//
//Output:
//4 2 5 1 3 6



//solution:



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || arr[0] == -1) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n) {
        Node* node = q.front();
        q.pop();

        // left child
        if (i < n) {
            if (arr[i] != -1) {
                node->left = new Node(arr[i]);
                q.push(node->left);
            }
            i++;
        }

        // right child
        if (i < n) {
            if (arr[i] != -1) {
                node->right = new Node(arr[i]);
                q.push(node->right);
            }
            i++;
        }
    }

    return root;
}

void inorder(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    inorder(node->left, result);
    result.push_back(node->val);
    inorder(node->right, result);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildTree(arr);

    vector<int> result;
    inorder(root, result);

    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i != (int)result.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
//Problem Statement:
//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

//Input Format:
//- First line contains integer N (number of nodes)
//- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

//Output Format:
//- Print nodes column by column from leftmost to rightmost vertical line

//Example:
//Input:
//7
//1 2 3 4 5 6 7

//Output:
//4
//2
//1 5 6
//3
//7

//Explanation:
//Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.


//solution:



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Build tree from level-order input where -1 indicates NULL
Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)arr.size()) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (i < (int)arr.size()) {
            if (arr[i] != -1) {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;
        }

        // Right child
        if (i < (int)arr.size()) {
            if (arr[i] != -1) {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
    }

    return root;
}

// Vertical order traversal using BFS
void verticalOrder(Node* root) {
    if (!root) return;

    // map keeps columns sorted by horizontal distance automatically
    map<int, vector<int>> columns;

    // BFS queue holds (node, horizontal distance)
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        columns[hd].push_back(node->data);

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Print column by column, left to right
    for (auto& [hd, values] : columns) {
        for (int idx = 0; idx < (int)values.size(); idx++) {
            cout << values[idx];
            if (idx != (int)values.size() - 1) cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = buildTree(arr);
    verticalOrder(root);

    return 0;
}
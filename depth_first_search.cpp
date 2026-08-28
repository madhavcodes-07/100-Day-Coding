//Problem: Perform DFS starting from a given source vertex using recursion.

//Input:
//- n
//- adjacency list
//- starting vertex s

//Output:
//- DFS traversal order


//solution:


#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited, result);
        }
    }
}

vector<int> dfs(int n, vector<vector<int>>& adj, int s) {
    vector<bool> visited(n, false);
    vector<int> result;
    dfsUtil(s, adj, visited, result);
    return result;
}

int main() {
    int n, m;
    cin >> n >> m; // number of vertices, number of edges
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line if the graph is directed
    }
    
    int s;
    cin >> s; // starting vertex
    
    vector<int> traversal = dfs(n, adj, s);
    
    for (int node : traversal) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
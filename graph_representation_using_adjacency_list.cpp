//Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

//Input:
// - n (vertices)
//- m (edges)
//- edges (u, v)

//Output:
// List of adjacency lists for each vertex


//solution:


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1); // 1-indexed; use adj(n) for 0-indexed
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line if the graph is directed
    }
    
    // Print adjacency list
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
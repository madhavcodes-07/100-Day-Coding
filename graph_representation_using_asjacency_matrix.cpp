//Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
//The graph may be directed or undirected.

//Input:
//- n (vertices)
//- m (edges)
//- m pairs (u, v)

//Output:
//- n x n adjacency matrix


//solution:


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // 0 = undirected, 1 = directed
    int isDirected;
    cin >> isDirected;
    
    vector<vector<int>> adj(n, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u][v] = 1;
        if (!isDirected) {
            adj[v][u] = 1;
        }
    }
    
    // Print the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
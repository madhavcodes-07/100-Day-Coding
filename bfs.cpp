//Problem: Perform BFS from a given source using queue.

//Input:
//- n
//- adjacency list
//- source s

//Output:
//- BFS traversal order



//solution:




#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<vector<int>>& adj, int s) {
    vector<bool> visited(n, false);
    vector<int> order;
    queue<int> q;
    
    visited[s] = true;
    q.push(s);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return order;
}

int main() {
    int n, m;
    cin >> n >> m; // n = number of nodes, m = number of edges
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line if graph is directed
    }
    
    int s;
    cin >> s;
    
    vector<int> result = bfs(n, adj, s);
    
    for (int node : result) cout << node << " ";
    cout << endl;
    
    return 0;
}

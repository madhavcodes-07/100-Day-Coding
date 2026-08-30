//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

//Output:
//- YES or NO


//soluution:


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, adj, visited))
                    return true;
            } 
            else if (neighbor != parent) {
                // visited, and not where we came from -> cycle
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(2));
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    Solution sol;
    bool result = sol.isCycle(V, edges);
    
    cout << (result ? "YES" : "NO") << endl;
    
    return 0;
}
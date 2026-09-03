//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).


//solution:


#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int V, vector<vector<int>>& adj) {
    // Step 1: Calculate in-degree of every vertex
    vector<int> indegree(V, 0);

    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    // Step 2: Put all vertices with in-degree 0 into queue
    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process vertices using queue
    vector<int> topo;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        // Remove u's outgoing edges
        for (int v : adj[u]) {
            indegree[v]--;

            // If in-degree becomes 0, add to queue
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Step 4: Check for cycle
    if (topo.size() != V) {
        cout << "Topological sorting is not possible (Cycle exists)" << endl;
        return;
    }

    // Step 5: Print topological order
    cout << "Topological Order: ";

    for (int node : topo) {
        cout << node << " ";
    }

    cout << endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    topologicalSort(V, adj);

    return 0;
}
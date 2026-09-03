//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.


//solution:


#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    
    // dist[i] = shortest distance from src to i
    vector<int> dist(V, INT_MAX);

    // Min-heap: {distance, node}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    // Source distance is 0
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Ignore outdated entry
        if (d > dist[u])
            continue;

        // Check all neighbours
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    // Input: u v weight
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});

        // For undirected graph, also add:
        // adj[v].push_back({u, w});
    }

    int src;
    cin >> src;

    vector<int> dist = dijkstra(V, adj, src);

    cout << "Shortest distances from source " << src << ":\n";

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " : INF\n";
        else
            cout << i << " : " << dist[i] << "\n";
    }

    return 0;
}
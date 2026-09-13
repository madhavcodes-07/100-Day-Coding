//Problem Statement
//Find shortest distances from source vertex in a weighted graph with non-negative weights.

//Input Format
//n m
//u v w
//source

//Output Format
//Distances to all vertices.

//Sample Input
//5 6
// 1 2 2
//1 3 4
//2 3 1
//2 4 7
//3 5 3
//4 5 1
//1

//Sample Output
//0 2 3 9 6

//Explanation
//Shortest distances computed via priority queue.



//solution:



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1); // adj[u] = {v, w}

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this line if graph is directed
    }

    int source;
    cin >> source;

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[source] = 0;

    // min-heap of {distance, vertex}
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // stale entry, skip

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << (i < n ? ' ' : '\n');
    }

    return 0;
}
//Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

//Input:
//- n vertices
//- m edges (u,v,w)

//Output:
//- Shortest distances OR NEGATIVE CYCLE

//solution:




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // n vertices, m edges

    vector<array<int, 3>> edges(m); // {u, v, w}
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cin >> src;

    const long long INF = LLONG_MAX / 2;
    vector<long long> dist(n, INF);
    dist[src] = 0;

    // Relax all edges (n-1) times
    for (int i = 0; i < n - 1; i++) {
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // One more pass to detect negative weight cycles
    bool hasNegativeCycle = false;
    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
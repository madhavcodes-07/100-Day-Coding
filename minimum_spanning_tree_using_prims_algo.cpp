//Problem Statement
//Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

//Input Format
//n m
//u v w


//Output Format
//Total weight of MST.

//Sample Input
//4 5
//1 2 3
//1 3 5
//2 3 1
//2 4 4
//3 4 2

//Sample Output
//6

//Explanation
//One possible MST edges: (2-3), (3-4), (1-2)



//solution:


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n + 1); // graph[u] = {(v, w), ...}

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<bool> visited(n + 1, false);
    // min-heap of (weight, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 1}); // start from node 1
    long long totalWeight = 0;
    int edgesUsed = 0;

    while (!pq.empty() && edgesUsed < n) {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        totalWeight += w;
        edgesUsed++;

        for (auto [v, weight] : graph[u]) {
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    cout << totalWeight << endl;

    return 0;
}

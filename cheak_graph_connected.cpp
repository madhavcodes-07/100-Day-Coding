//Problem Statement
//Using BFS or DFS, check if the entire graph is connected.

//Input Format
//n m
//edges

//Output Format
//CONNECTED
//NOT CONNECTED

//Sample Input
//4 2
//1 2
//3 4

//Sample Output
//NOT CONNECTED




//solution:




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int count = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                count++;
                q.push(v);
            }
        }
    }

    if (count == n) {
        cout << "CONNECTED" << endl;
    } else {
        cout << "NOT CONNECTED" << endl;
    }

    return 0;
}
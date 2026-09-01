//Problem: Detect cycle in directed graph using DFS and recursion stack.

//Output:
//- YES if cycle exists


//solution:


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& recStack) {
        visited[node] = 1;
        recStack[node] = 1;

        for (int next : graph[node]) {
            if (!visited[next]) {
                if (dfs(next, graph, visited, recStack)) {
                    return true;
                }
            } else if (recStack[next]) {
                // back edge to a node currently in the recursion stack -> cycle
                return true;
            }
        }

        recStack[node] = 0; // done exploring this node, remove from recursion stack
        return false;
    }

    bool hasCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
        }

        vector<int> visited(n, 0);
        vector<int> recStack(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, recStack)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m; // n = number of nodes, m = number of directed edges
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;
    cout << (sol.hasCycle(n, edges) ? "YES" : "NO") << endl;
    return 0;
}
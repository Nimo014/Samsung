#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent_node, vector<int>& visited, vector<int>& parent, const vector<vector<int>>& adj, vector<int>& cycle) {
    visited[node] = 1; 
    for (int child : adj[node]) {
        if (child == parent_node) continue;
        if (!visited[child]) { 
            parent[child] = node; 
            if (dfs(child, node, visited, parent, adj, cycle)) {
                return true;
            }
        }
        else { 
            cycle.push_back(node);
            int current = node;
            while (current != child) {
                cycle.push_back(current);
                current = parent[current];
            }
            cycle.push_back(child);
            return true; 
        }
    }
    return false;
}

bool find_cycle(int n, int m) {
    vector<vector<int>> adj(n + 1);
    vector<int> visited(n + 1, 0); 
    vector<int> parent(n + 1, -1); 
    vector<int> cycle;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            parent[i] = i;
            if (dfs(i, -1, visited, parent, adj, cycle)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    if (find_cycle(n, m)) {
        cout << "Cycle found";
    } else {
        cout << "No cycle found";
    }
    return 0;
}

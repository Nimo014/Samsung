#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
int n, m;
vector<int> adj[MAXN];
int visit[MAXN] = {}; 
int parent[MAXN] = {};
int min_cycle_sum = INT_MAX;
vector<int> min_cycle;

void dfs(int node) {
    visit[node] = 1; 
    
    for (int child : adj[node]) {
        if (visit[child]) { 
            vector<int> cycle;
            int cycle_sum = child; 
            cycle.push_back(node);
            
            int current = node;
            while (current != child) {
                cycle_sum += current;
                current = parent[current];
                cycle.push_back(current);
            }
            
            if (cycle_sum < min_cycle_sum) {
                reverse(cycle.begin(), cycle.end());
                sort(cycle.begin(), cycle.end());
                min_cycle = cycle;
                min_cycle_sum = cycle_sum;
            }
        }
        else{ 
            parent[child] = node;
            dfs(child);
            
        }
    }

    visit[node] = 0; 
}

int main() {
    cin >> n >> m;
    
    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            parent[i] = i;
            dfs(i);
        }
    }
    
    if (!min_cycle.empty()) {
        for (int node : min_cycle) {
            cout << node << ' ';
        }
    } else {
        cout << "No cycle found";
    }

    return 0;
}

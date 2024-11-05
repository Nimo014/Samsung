#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<int>> dp;

int findCost(int mask, int src) {
    if (mask == (1 << n) - 1) {
        return graph[src][0]; 
    }
    if (dp[mask][src] != -1) return dp[mask][src];

    int cost = 1e9;
    for (int node = 0; node < n; node++) {
        if ((mask & (1 << node)) == 0) {
            cost = min(cost, findCost(mask | (1 << node), node) + graph[src][node]);
        }
    }
    return dp[mask][src] = cost;
}

int solve() {
    cin >> n;
    graph.assign(n, vector<int>(n));
    dp.assign(1 << n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>graph[i][j];
        }
    }

    return findCost(1, 0);
}

int main() {
    int t;
    cin>>t;
    for (int test = 1; test <= t; test++) {
        cout<<solve()<<"\n";
    }
    return 0;
}

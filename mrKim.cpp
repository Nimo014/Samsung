#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<int>> dp;

int findCost(int mask, int src) {
    if (src == n - 1) return (mask == (1 << n) - 1) ? 0 : 1e9;
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
    n += 2;
    vector<pair<int, int>> coord(n);
    int x, y; 
    cin>>x>>y;
    coord[0] = {x, y};
    cin>>x>>y;
    coord[n-1] = {x, y};
    for(int i=1; i<n-1; i++){
        cin>>x>>y;
        coord[i] = {x, y};
    }    

    graph.assign(n, vector<int>(n));
    dp.assign(1 << n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int wt = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
            graph[i][j] = graph[j][i] = wt;
        }
    }

    return findCost(1, 0);
}

int main() {
    for (int test = 1; test <= 10; test++) {
        cout << "# " << test << " " << solve() << "\n";
    }
    return 0;
}

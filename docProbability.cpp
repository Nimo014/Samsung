#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define p pair<int, double>

void solve(int i, int t, vector<vector<p>>& adj, vector<double>& prob, double curr) {
    if (t <= 0) {
        prob[i] += curr; 
        return; 
    }
    
    for (auto child : adj[i]) {
        solve(child.first, t - 10, adj, prob, curr * child.second);
    }
}

int main() {
    int test;
    cin >> test; 
    
    while (test--) { 
        int n, m, t;
        cin >> n >> m >> t;
        vector<vector<p>> adj(n + 1); 
        vector<double> prob(n + 1, 0.0); 
        
        for (int i = 0; i < m; i++) {
            int a, b;
            double c; 
            cin >> a >> b >> c;
            adj[a].push_back({b, c}); 
        }
        
        solve(1, t, adj, prob, 1.0);
        
        int idx = -1;
        double val = 0.0;
        for (int i = 1; i <= n; i++) {
            if (prob[i] > val) {
                idx = i;
                val = prob[i];
            }
        }
        
        cout << "Answer: " << idx << " " << fixed << setprecision(6) << val << endl; 
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void solve(int i, const vector<int>& oilMines, vector<bool>& visited,
                        int minV, int maxV, int sum, int nodes, int& ans, int companies) {
    // Base Case
    if (visited[i]) {
        int newMin = min(sum, minV);
        int newMax = max(sum, maxV);

        if (nodes == companies - 1) {
            ans = min(ans, newMax - newMin);
        }
        return;
    }

    // Main Case
    visited[i] = true;
    int j = (i + 1) % oilMines.size();

    solve(j, oilMines, visited, minV, maxV, sum + oilMines[i], nodes, ans, companies);

    int newMin = min(sum, minV);
    int newMax = max(sum, maxV);

    solve(j, oilMines, visited, newMin, newMax, oilMines[i], nodes + 1, ans, companies);

    visited[i] = false;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int companies, mines;
    cin >> companies >> mines;

    vector<int> oilMines(mines);
    for (int i = 0; i < mines; i++) {
        cin >> oilMines[i];
    }

    int ans = INT_MAX;
    vector<bool> visited(mines, false);
    
    for (int i = 0; i < mines; i++) {
        solve(i, oilMines, visited, INT_MAX, INT_MIN, 0, 0, ans, companies);
    }

    cout << ans << endl;
    }
    return 0;
}

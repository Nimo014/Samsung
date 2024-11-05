#define INT_MAX 999999
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int findLeft(const vector<bool>& visited, int index) {
    for (int i = index; i > 0; i--) {
        if (!visited[i]) return i;
    }
    return INT_MAX;
}

int findRight(const vector<bool>& visited, int index, int n) {
    for (int i = index + 1; i <= n; i++) {
        if (!visited[i]) return i;
    }
    return INT_MAX;
}

void solve(const vector<int>& gate, vector<int>& men, vector<bool>& visited, int x, int y, int z, int distance, int& ans, int cur_gate, int n) {
    if (distance >= ans) return;

    if (men[cur_gate] == 0) {
        if (cur_gate == x) cur_gate = y;
        else if (cur_gate == y) cur_gate = z;
        else {
            ans = min(ans, distance);
            return;
        }
    }

    int l = findLeft(visited, gate[cur_gate]);
    int r = findRight(visited, gate[cur_gate], n);
    int costL = abs(gate[cur_gate] - l) + 1;
    int costR = abs(gate[cur_gate] - r) + 1;

    if (costL <= costR) {
        visited[l] = true;
        men[cur_gate]--;
        solve(gate, men, visited, x, y, z, distance + costL, ans, cur_gate, n);
        visited[l] = false;
        men[cur_gate]++;
    }
    if (costR <= costL) {
        visited[r] = true;
        men[cur_gate]--;
        solve(gate, men, visited, x, y, z, distance + costR, ans, cur_gate, n);
        visited[r] = false;
        men[cur_gate]++;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> gate(4), men(4);
    for (int i = 1; i <= 3; i++) cin >> gate[i];
    for (int i = 1; i <= 3; i++) cin >> men[i];

    int ans = INT_MAX;
    vector<bool> visited(n + 1, false);

    solve(gate, men, visited, 1, 2, 3, 0, ans, 1, n);
    solve(gate, men, visited, 1, 3, 2, 0, ans, 1, n);
    solve(gate, men, visited, 2, 1, 3, 0, ans, 2, n);
    solve(gate, men, visited, 2, 3, 1, 0, ans, 2, n);
    solve(gate, men, visited, 3, 1, 2, 0, ans, 3, n);
    solve(gate, men, visited, 3, 2, 1, 0, ans, 3, n);

    cout << ans << endl;

    return 0;
}

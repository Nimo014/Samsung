#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(const vector<int>& a, vector<int>& vis, int p1, int p2, int n, int& ans) {
    // Check if the current path results in a new maximum for p1
    if (p1 == p2) {
        ans = max(ans, p1);
    }

    // Iterate through each element to decide the next moves
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) {  // If the element is not visited
            vis[i] = 1;     // Mark it as visited
            solve(a, vis, p1 + a[i], p2, n, ans); // Include in p1
            solve(a, vis, p1, p2 + a[i], n, ans); // Include in p2
            vis[i] = 0;     // Backtrack: unmark the element
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);  // Use vector for dynamic size
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> vis(n, 0); // Visited array
    int ans = -1;          // Initialize answer
    solve(a, vis, 0, 0, n, ans); // Start the recursive solving

    cout << ans; // Output the maximum sum found
    return 0;
}

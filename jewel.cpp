#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;

bool valid(int x, int y, const vector<vector<int>>& mat, const vector<vector<bool>>& visited) {
    return (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && mat[x][y] != 1);
}

void print(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int x, int y, int jewels, int myAns, vector<vector<int>>& mat, vector<vector<bool>>& visited, const vector<vector<int>>& sec) {
    if (x == n - 1 && y == n - 1) {
        ans = max(ans, jewels);
        if (ans == myAns) print(mat);
        return;
    }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for (int i = 0; i < 4; i++) {
        int m = x + dx[i];
        int n = y + dy[i];

        if (valid(m, n, mat, visited)) {
            visited[m][n] = true;
            int originalValue = mat[m][n];
            
            if (mat[m][n] == 2) {
                mat[m][n] = 3;
                solve(m, n, jewels + 1, myAns, mat, visited, sec);
            } else {
                mat[m][n] = 3;
                solve(m, n, jewels, myAns, mat, visited, sec);
            }

            // backtrack
            visited[m][n] = false;
            mat[m][n] = originalValue;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        vector<vector<int>> mat(n, vector<int>(n));
        vector<vector<int>> sec(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];

        // Copy the matrix to sec for backtracking
        sec = mat;

        visited[0][0] = true;
        mat[0][0] = 3;
        ans = -1;
        
        solve(0, 0, 0, 999999, mat, visited, sec); // Initial call for maximum jewels

        cout << ans << endl;

        int myAns = ans;
        ans = -1;

        solve(0, 0, 0, myAns, mat, visited, sec); // Call to print path if it reaches max jewels
    }
    return 0;
}

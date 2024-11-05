#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int c, r;

bool canCheck(vector<vector<int>>& grid, int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == 1;
}

int bfs(vector<vector<int>>& grid, int s1, int s2) {
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    queue<pair<int, int>> q;
    q.push({s1, s2});
    grid[s1][s2] = 2;

    int time = 0;

    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) { 
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int m = x + dx[j];
                int n = y + dy[j];

                if (canCheck(grid, m, n)) {
                    q.push({m, n});
                    grid[m][n] = 2;
                }
            }
        }
        time++;
    }
    return time;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> c >> r;
        vector<vector<int>> grid(r, vector<int>(c));
    
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> grid[i][j];

        int x1, x2;
        cin >> x2 >> x1;
        x2--;
        x1--;
        if (grid[x1][x2] == 0) {
            cout << "#CASE " << i << ": 0" << endl;
        } else {
            int ans = bfs(grid, x1, x2);  // Assuming x1 and x2 are zero-indexed
            cout << "#CASE " << i << ": " << ans << endl;
        }
    }
}

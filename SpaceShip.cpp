#include <bits/stdc++.h>
using namespace std;

int n;
int dp[100][5][6][2];

int findMaxCoins(int row, int col, int effectRange, bool bombUsed, vector<vector<int>>& grid) {

    // base
    if (row < 0) return 0;

    // find enemy and no bomb and no immunity
    if (grid[row][col] == 2 && !bombUsed && effectRange > 5) return 0;

    // memo
    if (dp[row][col][effectRange][bombUsed] != -1) {
        return dp[row][col][effectRange][bombUsed];
    }

    // collect coin
    int coinCollected = (grid[row][col] == 1) ? 1 : 0;
    int maxCoins = 0;

    // Transition
    for (int offset = -1; offset <= 1; ++offset) {
        int newCol = col + offset;
        
        // isValid
        if (newCol < 0 || newCol >= 5) continue;

        if (!bombUsed || grid[row][col] == 2) { 
            // Use Bomb
            maxCoins = max(maxCoins, findMaxCoins(row - 1, newCol, effectRange + 1, false, grid));
        } else {
            maxCoins = max(maxCoins, max(
                findMaxCoins(row - 1, newCol, 1, true, grid),   // Don't Use Bomb
                findMaxCoins(row - 1, newCol, effectRange + 1, false, grid) // Use Bomb
            ));
        }
    }

    return dp[row][col][effectRange][bombUsed] = maxCoins + coinCollected;
}

int main() {
    int t;
    cin >> t;

    for (int test = 1; test <= t; ++test) {
        cin >> n;
        
        vector<vector<int>> grid(n, vector<int>(5));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> grid[i][j];
            }
        }

        memset(dp, -1, sizeof(dp));

        cout << "#" << test << " ";
        int startCol = 2;
        int res = 0;
        for (int i = -1; i <= 1; ++i) {
            res = max(res, findMaxCoins(n - 1, startCol + i, 1, true, grid));
        }

        cout << res << endl;
    }
    return 0;
}

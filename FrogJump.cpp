#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, sX, sY, tX, tY;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    vector<vector<int>> dis(n, vector<int>(n, 0));
    vector<vector<int>> vis(n, vector<int>(n, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cin >> sX >> sY >> tX >> tY;

    // Directions for movement: down, right, up, left
    int dirX[] = {1, 0, -1, 0};
    int dirY[] = {0, 1, 0, -1};

    // Initialize BFS
    q.push({sX, sY});
    vis[sX][sY] = 1;
    dis[sX][sY] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            // Check if new position is valid and not yet visited
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && mat[newX][newY] == 1 && !vis[newX][newY]) {
                // Horizontal movement cost
                if (i == 0 || i == 2) {  // Moving vertically (up or down)
                    dis[newX][newY] = dis[x][y];
                } else {  // Moving horizontally (left or right)
                    dis[newX][newY] = dis[x][y] + 1;
                }

                vis[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }

    cout << dis[tX][tY];
    return 0;
}

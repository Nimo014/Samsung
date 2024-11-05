#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define p pair<int,int>

int bfs(int x1, int y1, int x2, int y2, vector<vector<int>>& grid) {
    vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));
    vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), -1));
    queue<p> q;
    q.push({x1, y1});
    visit[x1][y1] = 1;
    dist[x1][y1] = 0;
    
    vector<p> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int newX = x + dir[i].first;
            int newY = y + dir[i].second;
            
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && !visit[newX][newY] && grid[newX][newY] == 1) {
                dist[newX][newY] = dist[x][y] + 1;
                visit[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }
    
    return dist[x2][y2];
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<p> rare(m);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;b--;
            rare[i] = {a, b};
        }
        
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int maxDist = INT_MIN;
                    for (int k = 0; k < m; k++) {
                        int distance = bfs(i, j, rare[k].first, rare[k].second, grid);
                        if (distance != -1) {
                            maxDist = max(maxDist, distance);
                        }
                    }
                    if (maxDist != INT_MIN) {
                        res = min(res, maxDist);
                    }
                }
            }
        }
        
        cout << "output: " << (res == INT_MAX ? -1 : res) << endl;
    }
    return 0;
}

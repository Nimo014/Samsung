#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;

        int s1, s2, d1, d2;
        cin >> s1 >> s2 >> d1 >> d2;

        s1--; s2--; d1--; d2--; 
        
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        vector<vector<int>> distance(r, vector<int>(c, -1));
        
        queue<pair<int, int>> q;
        q.push({s1, s2});
        visited[s1][s2] = true;
        distance[s1][s2] = 0;

        int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int m = x + dx[i];
                int n = y + dy[i];

                if (m >= 0 && m < r && n >= 0 && n < c && !visited[m][n]) {
                    q.push({m, n});
                    visited[m][n] = true;
                    distance[m][n] = distance[x][y] + 1;
                }
            }
        }
        cout << distance[d1][d2] << endl;
    }
    return 0;
}

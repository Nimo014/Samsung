#include <iostream>
#include <vector>
using namespace std;

bool solve(int node, int c, const vector<vector<int>>& adj_matrix, vector<int>& color, vector<int>& visit) {
    visit[node] = 1;
    color[node] = c;
    for (int child = 0; child < adj_matrix.size(); ++child) {
        if (adj_matrix[node][child] == 1) {
            if (!visit[child]) {
                if (!solve(child, !c, adj_matrix, color, visit)) {
                    return false;
                }
            } else if (color[node] == color[child]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj_matrix(n, vector<int>(n));
    vector<int> visit(n, 0);
    vector<int> color(n, -1);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj_matrix[i][j];
        }
    }
        
    for (int i = 0; i < n; ++i) {
        if (!visit[i] && !solve(i, 0, adj_matrix, color, visit)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
       cout << color[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}

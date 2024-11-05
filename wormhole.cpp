#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int res;
int visit[20] = {0}; 

struct wormhole {
    int x1, y1, x2, y2, cost;
};

int compute(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve(int x, int y, int dstX, int dstY, vector<wormhole>& pos, int cost, int n) {
    
    if (x == dstX && y == dstY) { 
        res = min(res, cost);
        return;
    }
    
    res = min(res, cost + compute(x, y, dstX, dstY));
    
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            visit[i] = 1; 
            solve(pos[i].x2, pos[i].y2, dstX, dstY, pos, cost + compute(x, y, pos[i].x1, pos[i].y1) + pos[i].cost, n);
            solve(pos[i].x1, pos[i].y1, dstX, dstY, pos, cost + compute(x, y, pos[i].x2, pos[i].y2) + pos[i].cost, n);
            visit[i] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<wormhole> pos(n);
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = 0; i < n; i++) {
            cin >> pos[i].x1 >> pos[i].y1 >> pos[i].x2 >> pos[i].y2 >> pos[i].cost;
        }

        res = 100000;
        solve(x1, y1, x2, y2, pos, 0, n);
        cout << res << endl;
    }
    return 0;
}

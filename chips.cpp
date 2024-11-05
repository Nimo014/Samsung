#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Config {
    int D, E, F, Sp;
};

int res;

void solve(int i, int cnt, int N, int D, int E, int F, int d, int e, const vector<Config>& c, int cost) {
    if (i == N || cnt == 3) {
        cost += D * d + E * e;
        res = max(res, cost);
        return;
    }

    solve(i + 1, cnt, N, D, E, F, d, e, c, cost);

    int multiplier = 1;
    while (D - c[i].D * multiplier >= 0 &&
           E - c[i].E * multiplier >= 0 &&
           F - c[i].F * multiplier >= 0) {
        solve(i + 1, cnt + 1, N,
              D - c[i].D * multiplier,
              E - c[i].E * multiplier,
              F - c[i].F * multiplier,
              d, e, c, cost + c[i].Sp * multiplier);
        ++multiplier;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int D, E, F, d, e, N;
        cin >> D >> E >> F >> d >> e >> N;

        vector<Config> c(N);
        for (int i = 0; i < N; ++i) {
            cin >> c[i].D >> c[i].E >> c[i].F >> c[i].Sp;
        }

        res = INT_MIN;
        solve(0, 0, N, D, E, F, d, e, c, 0);
        cout << res << endl;
    }
    return 0;
}

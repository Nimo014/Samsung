#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, const vector<int>& a, int n, int k) {
    int currentCows = 1;
    int leftmost = 0;
    
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[leftmost] >= x) {
            leftmost = i;
            ++currentCows;
            if (currentCows == k) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }

        sort(a.begin(), a.end());
        
        int l = 0, r = a[n - 1] - a[0] + 1;
        
        while (r - l > 0) {
            int m = (l + r + 1) / 2;
            
            if (isValid(m, a, n, k)) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        cout << l << '\n';
    }
}

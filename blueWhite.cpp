#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 129;
int white = 0, blue = 0;

void solve(int arr[maxn][maxn], int size, int si, int sj) {
    if (size == 0) return;
    int sum = arr[si + size - 1][sj + size - 1];
    if (sj - 1 >= 0) sum -= arr[si + size - 1][sj - 1];
    if (si - 1 >= 0) sum -= arr[si - 1][sj + size - 1];
    if (si - 1 >= 0 && sj - 1 >= 0) sum += arr[si - 1][sj - 1];
    if (sum == 0) {
        white++;
        return;
    }
    if (sum == size * size) {
        blue++;
        return;
    }
    solve(arr, size / 2, si, sj);
    solve(arr, size / 2, si + size / 2, sj);
    solve(arr, size / 2, si, sj + size / 2);
    solve(arr, size / 2, si + size / 2, sj + size / 2);
}

int main() {
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++) {
        white = 0;
        blue = 0;
        int size;
        cin >> size;
        int arr[maxn][maxn];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> arr[i][j];
                if (i - 1 >= 0) arr[i][j] += arr[i - 1][j];
                if (j - 1 >= 0) arr[i][j] += arr[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0) arr[i][j] -= arr[i - 1][j - 1];
            }
        }
        solve(arr, size, 0, 0);
        cout << "Case #" << l << endl;
        cout << white << " " << blue << endl;
    }
    return 0;
}

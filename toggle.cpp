#include <bits/stdc++.h>

using namespace std;

int n, m, k;
const int MN = 1000;
char a[MN][MN];

int main()
{
    int n, m, k;
    int res = 0;
    cin>>n>>m>>k;
    vector<vector<char>> grid(n, vector<char>(m));
    unordered_map<string, int> mp;
    
    for(int i = 0; i < n; i++){
        string row = "";
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
            row += grid[i][j];
        }
        mp[row]++;

    }
    
    
    for(auto it : mp){
        string row = it.first;
        int freq = it.second;
        
        int cnt = 0;
        
        for(auto ch : row){
            if(ch == '0') cnt++;
        }
        
        if(cnt <= k && (k - cnt) % 2 == 0){
            res = max(res, freq);
        }
    }
    cout << res;
    
    return 0;
}
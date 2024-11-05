#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, z;
        cin>>n>>z;
        vector<int> arr(n + 1);
        vector<vector<int>> dp(n + 1, vector<int>(z + 1, INT_MAX));
        
        for(int i=1; i<=n; i++)  cin>>arr[i];
        
        for(int i=1; i<=n; i++) dp[i][1]=arr[i] * (n-i+1);
        
        for(int i=1; i<=n; i++){
            for(int j=2; j<=z; j++){
                for(int k=i+1; k<=n; k++){
                    dp[i][j]=min(dp[i][j], dp[k][j-1]) + arr[i]*(k-i);
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i=1; i<=n; i++){
            ans=min(ans,dp[i][z]);
        }
        
        cout<<ans;
    }
    return 0;
}
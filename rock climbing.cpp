#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll n,m;


ll res=11;

void dfs(int i, int j,vector<vector<int>>& grid, vector<vector<int>>& visit,int curr)
{
    if(i<0 || j<0 || i>=n || j>=m || visit[i][j] || grid[i][j] == 0)return;
    
    if(grid[i][j]==3)
    {
        if(res>curr) res=curr;
        return;
    }

   
    visit[i][j]=1;
    int up = i - 1;
    while(up>=0 && grid[up][j]==0)
    {
        up--;
    }

    if(up>=0 && grid[up][j]!=0 && !visit[up][j])
    {
        dfs(up, j, grid, visit, max(curr, i - up));
    }

    int down=i+1;
    while((down)<n && grid[down][j]==0)
    {
        down++;
    }
    
    if((down)<n && grid[down][j]!=0 && !visit[down][j])
    {
      
        dfs(down, j, grid, visit, max(curr, down - i));
    }


    if((j+1)<m && grid[i][j+1]!=0 && visit[i][j+1]==0)
    {
        dfs(i, j+1, grid, visit, curr);
    }
    if((j-1)>=0 && grid[i][j-1]!=0 && visit[i][j-1]==0)
    {
         dfs(i, j-1, grid, visit, curr);
    }

    visit[i][j]=0;
    
    return;
    
}
 

int main()
{

    cin>>n>>m;
    res=11;



    vector<vector<int>> grid(n, vector<int>(m,0));
    vector<vector<int>> visit(n, vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
        
    
    dfs(n-1, 0, grid, visit, 0);
    cout<<res<<endl;
 
    
return 0;
}


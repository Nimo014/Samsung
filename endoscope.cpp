#include<bits/stdc++.h>
using namespace std;



bool find(char c, string &s){
    int n = s.size();
    for(int i=0; i<n; i++){
        if(c==s[i])return true;
    }
    return false;
}


int main() {
    int t; cin>>t;
    map<int, string> mp;
    
    mp[1] = "URDL";
    mp[2] = "UD";
    mp[3] = "RL";
    mp[4] = "UR";
    mp[5] = "RD";
    mp[6] = "LD";
    mp[7] = "UL";
    
  
    while(t--){
        int n, m, x, y, len; cin>>n>>m>>x>>y>>len;
        vector<vector<int>> grid(n, vector<int> (m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        vector<vector<int>> visit(n, vector<int> (m, 0));
        queue<vector<int>> q;
        q.push({x, y, len-1});
        visit[x][y]=1;
        int res = 1;
        
        while(q.size()){
            int x = q.front()[0];
            int y = q.front()[1];
            int l = q.front()[2];
            q.pop();

            if(l == 0) continue;
            
            // up && find if is it connected
            if(x>0 && !visit[x - 1][y] && find('U', mp[grid[x][y]]) && find('D', mp[grid[x-1][y]])){
                visit[x-1][y]=1;
                q.push({x-1, y, l-1});
                res++;
            }

            // right && find if is it connected
            if(y+1<m && !visit[x][y + 1] && find('R', mp[grid[x][y]]) && find('L', mp[grid[x][y+1]])){
                visit[x][y+1]=1;
                q.push({x, y+1, l-1});
                res++;
            }   

            // left && find if is it connected
            if(x+1<n && !visit[x+1][y] && find('D', mp[grid[x][y]]) && find('U', mp[grid[x+1][y]])){
                visit[x+1][y]=1;
                q.push({x+1, y, l-1});
                res++;
            }
            
            // down && find if is it connected
            if(y>0 && !visit[x][y-1] && find('L', mp[grid[x][y]]) && find('R', mp[grid[x][y-1]])){
                visit[x][y-1]=1;
                q.push({x, y-1, l-1});
                res++;
            }     
        }

        cout<<res<<"\n";
    }
    return 0;
}
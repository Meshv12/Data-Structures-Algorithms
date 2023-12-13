#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //{{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];
        int freshcnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else{
                    vis[i][j] = 0;
                }

                if(grid[i][j] == 1) freshcnt++;
            }
        }

        vector<pair<int,int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int maxtime = 0;
        int cnt = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            maxtime = max(maxtime, t);
            q.pop();

            for(auto it: dir){
                int nrow = r + it.first;
                int ncol = c + it.second;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                  vis[nrow][ncol] != 2 && grid[nrow][ncol] ==1)    // not visited and grid fresh orange
                  {
                    q.push({{nrow, ncol,}, t+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                  }
            }
        }

        if(cnt < freshcnt) return -1;
        return maxtime;
    }
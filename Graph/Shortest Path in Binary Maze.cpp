#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) 
    {
        if(source.first == destination.first &&         //edge case
            source.second == destination.second)
            return 0; 
            
            
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});
        
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto it = q.front();
            int wt = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            
            for(auto it : dir){
                int nrow = row + it.first;
                int ncol = col + it.second;
                
                if(nrow >= 0 && ncol >=0 && nrow < n && ncol < m && grid[nrow][ncol] == 1 && wt + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + wt;
                    if(nrow == destination.first && ncol == destination.second){
                        return dist[nrow][ncol];
                    }
                    
                    q.push({wt + 1, {nrow, ncol}});        // add to queue
                }
            }
            
        }
        
        return -1;
    }
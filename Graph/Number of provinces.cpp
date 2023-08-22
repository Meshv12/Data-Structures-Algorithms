#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int node, vector<int> adjLs[], int vis[]){
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(vis[it] == 0){
                dfs(it, adjLs, vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V];
        
        // convert adjecent matrix to adjecent list 
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1 && i != j){  // Self loop can't consider
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int cnt = 0;
        
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){      // if visited arr is not visited then cnt++ and mark all connected vertices
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        
        return cnt;
    }
};
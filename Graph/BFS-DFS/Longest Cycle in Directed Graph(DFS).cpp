#include <bits/stdc++.h>
using namespace std;

// Use code of detect cycle in directed graph (DFS) --> pathvis array concept 
// additionally here maintain count array for get longest cycle

class Solution {
public:
    int ans = -1;

    void dfs(int node, vector<int> &edges, vector<int> &vis, vector<int> &pathvis,  vector<int> &count){
        if(node != -1){

            vis[node] = 1;
            pathvis[node] = 1;

            int adjnode = edges[node];

            if(adjnode != -1 && !vis[adjnode]){
                count[adjnode] = count[node] + 1;
                dfs(adjnode, edges, vis, pathvis, count);
            }
            else if(adjnode != -1 && pathvis[adjnode] == 1){        // cycle found
                ans = max(ans, abs(count[node] - count[adjnode]) + 1);
            }

            pathvis[node] = 0;

        }
    }

    int longestCycle(vector<int>& edges) {   // don't need adj list 
        int n = edges.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> count(n, 1);

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, edges, vis, pathvis, count);
            }
        }

        return ans;
    }
};
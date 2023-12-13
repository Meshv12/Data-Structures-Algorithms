#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        /*
         take action on node after entering the node
        */

        for(auto it : adj[node]) {
            /*
             take action on child(adjecent) node BEFORE entering child(adjecent) Node
            */
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
            /*
             take action on child(adjecent) node AFTER exiting child(adjecent) Node
            */
        }

        /*
         Take action on node after exiting the node
        */

    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfs(start, adj, vis, ls); 
        return ls; 
    }
};
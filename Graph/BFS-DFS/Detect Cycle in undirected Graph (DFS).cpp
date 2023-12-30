#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int node, int parent, int vis[], vector<int> adj[]){
        vis[node] = 1;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode, node, vis, adj) == true)
                    return true;
            }
            else if(adjnode != parent)    // Prev visited but not the parent so it is definetly cycle
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj) == true)
                    return true;
            }
        }
        return false;
    }
};

/*
int detectCycleInDirectedGraph(int V, vector < pair < int, int >> & edges){

    // adj list 
    
  vector<int> adj[V+1];
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adj[u].push_back(v);
    //adj[v].push_back(u);
  }*/
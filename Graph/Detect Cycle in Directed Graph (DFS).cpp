#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis){
  vis[node] = 1;
  pathVis[node] = 1;
        
  for(auto it : adj[node]){
    // if node is not visited
    if(!vis[it]){
      if(dfsCheck(it, adj, vis, pathVis) == true)
        return true;
    }
    // if has been prev visited and also path visited means it is make a cycle
    else if(vis[it] && pathVis[it]){
       return true;
    }
  }
        
  pathVis[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int V, vector < pair < int, int >> & edges){
  vector<int> adj[V+1];
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adj[u].push_back(v);
    //adj[v].push_back(u);
  }

  vector<int> vis(V+1,0);
  vector<int> pathVis(V+1,0);
  for(int i = 0; i<V; i++){
    if(!vis[i]){
      if(dfsCheck(i, adj, vis, pathVis) == true)
        return true;
      }
    }
    return false;
}
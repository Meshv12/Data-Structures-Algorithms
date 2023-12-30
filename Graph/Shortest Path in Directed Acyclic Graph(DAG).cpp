#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[]){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            int v = it.first;
            if(vis[v] == 0){
                topoSort(v, vis, st, adj);
            }
        }
        
        st.push(node);
     }
     
vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N+1];
        // make adj list
        for(int i = 0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        // Topo sort using dfs
        vector<int> vis(N+1, 0);
        stack<int> st;
        
        for(int i = 0; i<N; i++){
            if(vis[i] == 0){
                topoSort(i, vis, st, adj);
            }
        }
        
        vector<int> dist(N);
        for(int i = 0; i<N; i++) dist[i] = 1e9;
        dist[0] = 0;  // given base
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[adjnode]){
                    dist[adjnode] = dist[node] + wt;
                }
            }
        }
        
        // if impossible to reach any vertex put it -1
        for(int i=0;i<dist.size();i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        
        return dist;
    }
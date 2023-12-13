#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // adj list
        vector<pair<int, int>> adj[n+1];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // {stops, {node, dist}}
        queue<pair<int, pair<int, int>>> q;  // also use priority queue we work on stops not on distance so save time use queue
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops > k) continue;
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                int wt = it.second;
                
                if(cost + wt < dist[adjnode] && stops <= k){
                    dist[adjnode] = cost + wt;
                    q.push({stops + 1, {adjnode, cost + wt}});
                }
            }
        }
        
        if(dist[dst] == 1e9) return -1;
        
        return dist[dst];
    }
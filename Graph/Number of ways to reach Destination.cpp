#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = (int)1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // adj list
        vector<pair<int, int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // min heap  {dist, node}
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
        vector<long> dist(n, 1e18);
        vector<int> cnt(n, 0);
        pq.push({0, 0});
        dist[0] = 0;
        cnt[0] = 1;
        
        while(!pq.empty()){
            long wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;
                
                // if we reach with min dist first time (copy - inherite cnt value)
                if(adjwt + wt < dist[adjnode]){
                    dist[adjnode] = adjwt + wt;
                    pq.push({adjwt + wt, adjnode});
                    cnt[adjnode] = cnt[node] % mod;
                }
                // we reach with min dist again (add cnt value)
                else if(adjwt + wt == dist[adjnode]){
                    cnt[adjnode] = (cnt[adjnode] + cnt[node]) % mod;
                }
            }
        }
        
        return cnt[n-1] % mod;
    }
};
#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int V, int edges, int source) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap
    vector<int> dist(V);
    for(int i = 0; i<V; i++) dist[i] = INT_MAX;
    pq.push({0, source});
    dist[source] = 0;        // Minimum dist from source to all nodes 

    // adj list
    vector<pair<int, int>> adj[V+1];
    for(int i = 0; i < vec.size(); i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }


    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int adjnode = it.first;
            int adjwt = it.second;
            if(wt + adjwt < dist[adjnode]){
                dist[adjnode] = wt + adjwt;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }

    return dist;
}
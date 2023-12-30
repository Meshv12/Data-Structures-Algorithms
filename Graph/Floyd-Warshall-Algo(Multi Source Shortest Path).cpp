#include<bits/stdc++.h>
using namespace std;

// Multi Source Shortest Path algoritm
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
// adj mat for vertices
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e9));
    for(auto it : edges){
        int u = it[0] - 1;
        int v = it[1] - 1;
        int wt = it[2];
        dist[u][v] = wt;
    }
    for(int i = 0; i<n; i++) dist[i][i] = 0;

    // floydWarshall Algo
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist[src-1][dest-1];
}
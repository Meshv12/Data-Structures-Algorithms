#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 1;
    void bfs(int i, vector<int>& color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(i);
        color[i] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    ans = 0;
                    return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for(int i = 0; i<V; i++){
            if(color[i] == -1){
                bfs(i, color, graph);
            }
        }

        if(ans == 1) return true;
        return false;
    }
};
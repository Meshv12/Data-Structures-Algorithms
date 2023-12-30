#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        int indegree[V];
        vector<int> revAdj[V];
        for(int i = 0; i<V; i++) indegree[i] = 0;

        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                // i -> it   convert to  it -> i
                revAdj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        vector<int> ans;
        queue<int> q;
        
        for(int i = 0; i<V; i++){  
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : revAdj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
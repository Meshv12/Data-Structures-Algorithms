#include <bits/stdc++.h>
using namespace std;

// Return one of possible topological sorting

vector<int> findSchedule(int numCourses, vector<pair<int, int>> &prerequisites) {
        int V = numCourses;
        vector<int> adj[V+1];
        for(auto it : prerequisites){
            //[u,v] ---> if we want to take u then v must be taken first 
            // v take first then u take

            int u = it.first;
            int v = it.second;
            adj[v].push_back(u);
        }

        int inDegree[V+1];
		for(int i = 0; i<=V; i++){
			inDegree[i] = 0;
		}
		
	    for(int i = 0; i < V; i++){
	        for(auto it : adj[i]){
	            inDegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++){    // This loop for first time finding 
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);  // This node is in your topo sort
	        
            // so remove it indegree from adj nodes
	        
	        for(auto it : adj[node]){
	            inDegree[it]--;
	            if(inDegree[it] == 0) q.push(it);
	        }
	    }
		
	    if(topo.size() == V) return topo;
        return {};
}
#include<bits/stdc++.h>
using namespace std;

// using DFS
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(vis[it] == 0){
	            dfs(it, vis, adj, st);
	        }
	    }
	    st.push(node);
	}
	
vector<int> topoSort(int V, vector<int> adj[]) 
{
	    vector<int> vis(V+1, 0);
	    stack<int> st;
	    
	    for(int i = 0; i < V; i++){
	       if(vis[i] == 0)
	          dfs(i, vis, adj, st);
	    }

	    vector<int> ans;
	    while(!st.empty()){
	        int a = st.top();
	        st.pop();
	        ans.push_back(a);
	    }
	    return ans;
}

// Using BFS --> Kahn's Algo --> Use to detect cycle or not in directed graph

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)
{
        // Make adj list
        vector<int> adj[V + 1];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        // find all the indegress
        int inDegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
              inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        { // This loop for first time finding
            if (inDegree[i] == 0)
            {
              q.push(i);
            }
        }
        vector<int> topo;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // This node is in your topo sort
            // so remove it from indegree {treaverse its neibours and remove indegree bt 1}

            for (auto it : adj[node])
            {
              inDegree[it]--;
              if (inDegree[it] == 0)
                  q.push(it);
            }
        }
        return topo;
}
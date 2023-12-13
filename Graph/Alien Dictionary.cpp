#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<int> adj[], int V)
{
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
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K+1];
        // make adj list of alien 
        for(int i = 0; i < N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            
            for(int ptr = 0; ptr < len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo;
        topo = topologicalSort(adj, K);
        
        string ans = "";
        for(auto it : topo){
            ans = ans + (char)(it + 'a');
        }
        
        return ans;
    }
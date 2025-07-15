#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, vector<int>> adj;
    vector<int> eulerPath;

    void dfs(int node)
    {
        while (!adj[node].empty())
        {
            int nextNode = adj[node].back();
            adj[node].pop_back(); // Remove the edge after visiting
            dfs(nextNode);
        }
        eulerPath.push_back(node); // Add node to Euler path after all edges are visited
    }

    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {

        unordered_map<int, int> indegree, outdegree;

        for (auto &edge : pairs)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // u --> v
            outdegree[u]++;
            indegree[v]++;
        }

        int startNode = pairs[0][0];

        // outdegree[node] - indegree[node] == 1 any node follow this condition then euler path start
        for (auto &it : adj)
        {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1)
            {
                startNode = node;
                break;
            }
        }

        dfs(startNode);
        reverse(eulerPath.begin(), eulerPath.end());

        vector<vector<int>> result;

        for (int i = 0; i < eulerPath.size() - 1; i++)
        {
            result.push_back({eulerPath[i], eulerPath[i + 1]});
        }

        return result;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int curr_node, int par, unordered_map<int, vector<int>> &adj, vector<bool> &hasApple)
    {
        int time_from_curr_node = 0;

        for (auto child : adj[curr_node])
        {
            if (child == par)
                continue;

            int time_from_child = dfs(child, curr_node, adj, hasApple);

            if (time_from_child > 0 || hasApple[child] == true)  // 3 cases (prefere book)
            {
                time_from_curr_node += (time_from_child + 2);
            }
        }

        return time_from_curr_node;
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return dfs(0, -1, adj, hasApple);
    }
};
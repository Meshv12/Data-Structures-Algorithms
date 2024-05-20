#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int par, unordered_map<int, vector<int>> &adj, string &labels, vector<int> &ans, vector<int> &alfas)
    {
        char l = labels[node];

        int before = alfas[l - 'a']; // before iteration

        alfas[l - 'a'] += 1; // plus itself

        for (auto it : adj[node])
        {
            if (it != par)
            {

                dfs(it, node, adj, labels, ans, alfas);
            }
        }

        int after = alfas[l - 'a']; // after iteration

        ans[node] = after - before;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n);
        vector<int> alfas(26, 0);

        dfs(0, -1, adj, labels, ans, alfas);

        return ans;
    }
};
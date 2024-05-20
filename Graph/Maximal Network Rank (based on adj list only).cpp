#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        unordered_map<int, unordered_set<int>> adj;
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                int s1 = adj[i].size();
                int s2 = adj[j].size();

                int total = s1 + s2;

                if (adj[i].find(j) != adj[i].end())
                    total--;

                ans = max(ans, total);
            }
        }

        return ans;
    }
};
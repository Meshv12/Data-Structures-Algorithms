#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // {wt, node}
        vector<int> vis(V, 0);
        pq.push({0, 0});

        int sum = 0;             // in worse case there are all Edges in pq so O(E)
        while (!pq.empty())
        {
            auto it = pq.top();         // take O(log E)
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue; // if node is visited it means it is already part of mst
            vis[node] = 1;
            sum += wt;
            // ans.push_back({parent, node}) if we have to ask to make MST

            for (auto it : adj[node])
            {
                int adjnode = it[0];
                int adjwt = it[1];

                if (vis[adjnode] == 0)
                {
                    pq.push({adjwt, adjnode});
                }
            }
        }

        return sum;
    }
};

// TC: O(E*log E)
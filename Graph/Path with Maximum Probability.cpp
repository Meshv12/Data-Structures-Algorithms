#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        unordered_map<int, vector<pair<int, double>>> adj;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<pair<double, int>> pq; // max heap based on probability(we need maximum path --> reverse Dijkstra's)
        vector<double> res(n, 0);

        res[start] = 1; // prob of going start node to start node is 100%(1)
        pq.push({1.0, start});

        while (!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            double prob = it.first;
            pq.pop();

            for (auto s : adj[node])
            {
                int adjnode = s.first;
                double adjprob = s.second;

                if (res[adjnode] < adjprob * prob)
                {
                    res[adjnode] = adjprob * prob;
                    pq.push({res[adjnode], adjnode});
                }
            }
        }

        return res[end];
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dist_for_0;
    int N;

    int dfs(int node, int par, unordered_map<int, vector<int>> &adj, vector<int> &count, int curr_depth)
    {

        dist_for_0 += curr_depth;

        int total_count = 1; // include that node

        for (auto adjnode : adj[node])
        {
            if (adjnode == par)
                continue;

            total_count += dfs(adjnode, node, adj, count, curr_depth + 1);
        }

        count[node] = total_count;

        return total_count;
    }

    void DFS(int node, int par, unordered_map<int, vector<int>> &adj, vector<int> &count, vector<int> &res)
    {

        for (auto adjnode : adj[node])
        {
            if (adjnode == par)
                continue;
            cout << adjnode << " " << count[adjnode] << endl;

            res[adjnode] = res[node] - count[adjnode] + (N - count[adjnode]);

            DFS(adjnode, node, adj, count, res);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        N = n;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dist_for_0 = 0;
        vector<int> count(n, 0); // this is count the nodes under particuler subtree including that node

        dfs(0, -1, adj, count, 0); // get ans for 0th node and get count vector(subtrees)

        vector<int> res(n, 0);
        res[0] = dist_for_0;

        DFS(0, -1, adj, count, res); // get ans for all nodes

        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find_ulti_parent(int node)
    { // Path Compression
        if (node == parent[node])
            return node;

        return parent[node] = find_ulti_parent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulti_u = find_ulti_parent(u);
        int ulti_v = find_ulti_parent(v);
        if (ulti_u == ulti_v)
            return;

        if (rank[ulti_u] < rank[ulti_v])
        {
            parent[ulti_u] = ulti_v;
        }
        else if (rank[ulti_v] < rank[ulti_u])
        {
            parent[ulti_v] = ulti_u;
        }
        else
        {
            parent[ulti_v] = ulti_u;
            rank[ulti_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulti_u = find_ulti_parent(u);
        int ulti_v = find_ulti_parent(v);
        if (ulti_u == ulti_v)
            return;

        if (size[ulti_u] < size[ulti_v])
        {
            parent[ulti_u] = ulti_v;
            size[ulti_v] += size[ulti_u];
        }
        else
        {
            parent[ulti_v] = ulti_u;
            size[ulti_u] += size[ulti_v];
        }
    }
};

class Solution
{
public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        map<int, vector<int>> val_to_node;

        for (int i = 0; i < vals.size(); i++)
        {
            int value = vals[i];

            val_to_node[value].push_back(i);
        }

        int result = 0;
        DisjointSet ds(n);

        vector<bool> is_active(n, 0); // starting ma badha inactive

        for (auto it : val_to_node)
        {

            vector<int> nodes = it.second;

            for (int u : nodes)
            {

                for (int v : adj[u])
                {
                    if (is_active[v] == true)
                    {
                        ds.unionBySize(u, v);
                    }
                }

                is_active[u] = true; // mark as active bcz we visit that node
            }

            vector<int> parents;

            // --> node is vec of value with 5 -->   5:(value) -> {1,3,4,5,7,8,9}:(nodes)
            // --> we have to check how many nodes are in same component.
            // --> after suppose 3 nodes in C-1 and 4 nodes in C-2. we use 3C2 and 4C2 --> nCr

            for (int u : nodes)
            {
                int ultimate_parent = ds.find_ulti_parent(u);

                parents.push_back(ultimate_parent);
            }

            int m = parents.size();
            sort(parents.begin(), parents.end());

            for (int j = 0; j < m; j++)
            {

                int curr_parent = parents[j];
                int cnt = 0;

                while (j < m && curr_parent == parents[j])
                {
                    cnt++;
                    j++;
                }
                j--;

                result += (cnt * (cnt - 1) / 2);
            }
        }

        return result + n;
    }
};
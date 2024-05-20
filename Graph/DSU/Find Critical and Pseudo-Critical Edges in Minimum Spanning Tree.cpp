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

// ******************** Kruskal Algo *********************

int kruskal(int n, vector<vector<int>> &edges, int skip, int add)
{
    DisjointSet ds(n);
    // sort(edges.begin(), edges.end(), customComparator);
    int ans = 0;
    int cnt = 0;

    if (add != -1)
    {
        ds.unionBySize(edges[add][0], edges[add][1]);
        cnt++;
        ans += edges[add][2];
    }

    for (int i = 0; i < edges.size(); i++)
    {
        if (skip == i)
            continue;

        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        if (ds.find_ulti_parent(u) != ds.find_ulti_parent(v))
        {
            cnt++;
            ans += wt;
            ds.unionBySize(u, v);
        }
    }

    if (cnt < n - 1)
    { // if we cann't make MST without that edge then we must have to include that edge
        return INT_MAX;
    }

    return ans;
}

class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            edges[i].push_back(i);
        }
        auto comparator = [&](auto &v1, auto &v2)
        {
            return v1[2] < v2[2];
        };

        sort(edges.begin(), edges.end(), comparator);

        int mstwt = kruskal(n, edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo_critical;

        for (int i = 0; i < edges.size(); i++)
        {
            if (kruskal(n, edges, i, -1) > mstwt)
            {
                critical.push_back(edges[i][3]);
            }
            else if (kruskal(n, edges, -1, i) == mstwt)
            {
                pseudo_critical.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo_critical};
    }
};
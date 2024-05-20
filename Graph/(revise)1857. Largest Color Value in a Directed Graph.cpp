#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n + 1, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        vector<vector<int>> t(n, vector<int>(26, 0));

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }

        int res = 0;
        int cnt = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            cnt++; // to know cycle present or not

            res = max(res, t[u][colors[u] - 'a']);

            for (auto v : adj[u])
            {
                for (int i = 0; i < 26; i++)
                {
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v] - 'a' == i));
                }

                inDegree[v]--;
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }

        if (cnt < n)
            return -1; // cycle prrsent

        return res;
    }
};
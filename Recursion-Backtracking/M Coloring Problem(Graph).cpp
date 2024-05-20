#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(int node, int color, bool graph[101][101], vector<int> &c, int n)
    {
        for (int k = 0; k < n; k++)
        {
            if (k != node && graph[node][k] == 1 && c[k] == color)
                return false;
        }

        return true;
    }

    bool solve(int node, bool graph[101][101], vector<int> &c, int m, int n)
    {
        if (node == n)
        {
            return true;
        }

        for (int color = 1; color <= m; color++)
        {
            if (possible(node, color, graph, c, n))
            {

                c[node] = color;
                if (solve(node + 1, graph, c, m, n) == true)
                    return true;
                c[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> c(n, 0);
        return solve(0, graph, c, m, n);
    }
};
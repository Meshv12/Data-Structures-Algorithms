#include<bits/stdc++.h>
using namespace std;

// Dijkstra
int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) 
    {
        int n = grid.size();
        int m = grid[0].size();
        pair<int, int> source = {0, 0};
        pair<int, int> destination = {n - 1, n - 1};

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        if (source.first == destination.first && source.second == destination.second)
            return 1;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {source.first, source.second}});

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        while (!q.empty())
        {
            auto it = q.front();
            int wt = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();

            for (auto it : dir)
            {
                int nrow = row + it.first;
                int ncol = col + it.second;

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 0 && wt + 1 < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = 1 + wt;

                    q.push({wt + 1, {nrow, ncol}}); // add to queue
                }
            }
        }
        if (dist[n - 1][n - 1] == (int)1e9)
            return -1;

        return dist[n - 1][n - 1];
    }

    // Using BFS --> Why it works??
    // --> We need to solve shortest path and here all edge weight is 1 (same) that's why BFS works

    class Solution
    {
    public:
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int shortestPathBinaryMatrix(vector<vector<int>> &grid)
        { // use grid as vis array
            int n = grid.size();
            int m = grid[0].size();
            if (grid[0][0] == 1)
                return -1;

            queue<pair<int, int>> q;
            q.push({0, 0});
            int dist = 0;

            while (!q.empty())
            {
                int N = q.size();

                while (N--)
                {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();

                    if (row == n - 1 && col == m - 1)
                        return dist + 1;

                    for (auto it : dir)
                    {
                        int nrow = it.first + row;
                        int ncol = it.second + col;

                        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 0)
                        {
                            grid[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    }
                }

                dist++;
            }

            return -1;
        }
    };
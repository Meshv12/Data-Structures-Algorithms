#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int f(int i, int j, vector<pair<int, int>> &th, vector<vector<int>> &grid)
    {
        int n = grid.size();

        int mini = INT_MAX;
        for (auto it : th)
        {
            mini = min(mini, abs(i - it.first) + abs(j - it.second));
        }

        return mini;
    }
    bool bfs(vector<vector<int>> grid, vector<pair<int, int>> &th, int mid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i == n - 1 && j == n - 1)
            {
                if (f(i, j, th, grid) < mid)
                    return false;

                return true;
            }

            if (f(i, j, th, grid) < mid)
            {
                continue;
            }

            for (auto it : dir)
            {
                int ni = i + it.first;
                int nj = j + it.second;

                if (ni < 0 || nj < 0 || ni >= n || nj >= n || grid[ni][nj] == 1)
                    continue;

                q.push({ni, nj});
                grid[ni][nj] = 1;
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return 0;

        vector<pair<int, int>> th;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == 1)
                {
                    th.push_back({i, j});
                }
            }
        }
        int low = 0, high = n;
        int ans = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (bfs(grid, th, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};
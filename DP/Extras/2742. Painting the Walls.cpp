#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[501][501];
    int f(int ind, int remaining_walls, vector<int> &cost, vector<int> &time, int n)
    {
        if (ind >= n)
        {
            if (remaining_walls <= 0)
                return 0;
            return 1e9;
        }
        if (dp[ind][remaining_walls] != -1)
            return dp[ind][remaining_walls];

        int take = cost[ind] + f(ind + 1, max(0, remaining_walls - 1 - time[ind]), cost, time, n);
        int not_take = f(ind + 1, remaining_walls, cost, time, n);

        return dp[ind][remaining_walls] = min(take, not_take);
    }

    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return f(0, n, cost, time, n);
    }
};
#include <bits/stdc++.h>
using namespace std;
// Memoization

int f(int ind, int T, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (T % nums[0] == 0)
            return T / nums[0];
        return 1e9;
    }

    if (dp[ind][T] != -1)
        return dp[ind][T];

    int notTake = 0 + f(ind - 1, T, nums, dp);
    int take = INT_MAX;
    if (nums[ind] <= T)
    {
        take = 1 + f(ind, T - nums[ind], nums, dp);
    }

    return dp[ind][T] = min(notTake, take);
}
int minimumElements(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int ans = f(n - 1, x, nums, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}

// Tabulation

int tabulation(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int T = 0; T <= x; T++)
    {
        if (T % nums[0] == 0)
            dp[0][T] = T / nums[0];
        else
            dp[0][T] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= x; T++)
        {

            int notTake = 0 + dp[ind - 1][T];
            int take = INT_MAX;
            if (nums[ind] <= T)
            {
                take = 1 + dp[ind][T - nums[ind]];
            }

            dp[ind][T] = min(notTake, take);
        }
    }

    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        return -1;
    return ans;
}

// Space optimization

int minimumElements(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<int> cur(x + 1, 0), prev(x + 1, 0);

    for (int T = 0; T <= x; T++)
    {
        if (T % nums[0] == 0)
            prev[T] = T / nums[0];
        else
            prev[T] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= x; T++)
        {

            int notTake = 0 + prev[T];
            int take = INT_MAX;
            if (nums[ind] <= T)
            {
                take = 1 + cur[T - nums[ind]];
            }

            cur[T] = min(notTake, take);
        }
        prev = cur;
    }

    int ans = prev[x];
    if (ans >= 1e9)
        return -1;
    return ans;
}
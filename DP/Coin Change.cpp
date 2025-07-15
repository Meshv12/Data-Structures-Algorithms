#include <bits/stdc++.h>
using namespace std;
// Memoization

class Solution
{
public:
    int dp[13][10001];
    int f(int ind, int k, vector<int> &nums, int n)
    {
        if (k == 0)
            return 0;
        if (ind >= n)
            return 1e9;

        if (dp[ind][k] != -1)
            return dp[ind][k];

        int n_pick = f(ind + 1, k, nums, n);
        int pick = 1e9;
        if (k >= nums[ind])
        {
            pick = 1 + f(ind, k - nums[ind], nums, n);
        }

        return dp[ind][k] = min(n_pick, pick);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp));
        int n = coins.size();
        int ans = f(0, amount, coins, n);

        return (ans == 1e9) ? -1 : ans;
    }
};

// Tabulation

class Solution1
{
public:
    int dp[13][10001];

    int coinChange(vector<int> &nums, int amount)
    {
        int n = nums.size();

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1e9;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int k = 0; k <= amount; k++)
            {

                int pick = 1e9;
                if (nums[i - 1] <= k)
                    pick = 1 + dp[i][k - nums[i - 1]];
                int n_pick = dp[i - 1][k];

                dp[i][k] = min(pick, n_pick);
            }
        }

        return dp[n][amount] == 1e9 ? -1 : dp[n][amount];
    }
};

// Space optimization
class Solution3
{
public:
    int dp[13][10001];

    int coinChange(vector<int> &nums, int amount)
    {
        int n = nums.size();
        
        vector<int> prev(amount + 1, 1e9);
        vector<int> temp(amount + 1, 1e9);

        temp[0] = prev[0] = 0;

        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= amount; j++) {
        //         if (j == 0)
        //             dp[i][j] = 0;
        //         else
        //             dp[i][j] = 1e9;
        //     }
        // }

        for (int i = 1; i <= n; i++)
        {
            for (int k = 0; k <= amount; k++)
            {

                int pick = 1e9;
                if (nums[i - 1] <= k)
                    pick = 1 + temp[k - nums[i - 1]];
                int n_pick = prev[k];

                temp[k] = min(pick, n_pick);
            }
            prev = temp;
        }

        return prev[amount] == 1e9 ? -1 : prev[amount];
    }
};
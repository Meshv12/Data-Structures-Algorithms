#include <bits/stdc++.h>
using namespace std;

// LIS Pattern

class Solution
{
public:
    int dp[1001][1003];

    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        memset(dp, 0, sizeof(dp));

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {

                int diff = nums[j] - nums[i] + 501;

                if (dp[j][diff] == 0)
                    dp[i][diff] = 2;
                else
                    dp[i][diff] = dp[j][diff] + 1;

                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int dp[1001][1003];

    int f(int ind, int d, vector<int> &nums)
    {
        if (ind < 0)
            return 0;

        if (dp[ind][d + 501] != -1)
            return dp[ind][d + 501];

        int ans = 0;
        for (int k = ind - 1; k >= 0; k--)
        {
            if ((nums[ind] - nums[k]) == d)
            {

                // found common diff then pass current ind to function and try to find more elements
                int cc = 1 + f(k, d, nums);
                ans = max(ans, cc);
            }
        }

        return dp[ind][d + 501] = ans;
    }

    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));

        int ans = 0; //   NEED TO TAKE TWO FIXED POINT i and j and find others from recursion
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                int d = nums[j] - nums[i];         // commom diff
                ans = max(ans, 2 + f(i, d, nums)); // 2 elements are nums[i] and nums[j] themself
            }
        }

        return ans;
    }
};
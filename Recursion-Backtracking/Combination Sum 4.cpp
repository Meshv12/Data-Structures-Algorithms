#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int sum, vector<int> &arr, vector<int> &dp)
    {
        if (sum < 0)
            return 0;
        if (sum == 0)
            return 1;
        if (dp[sum] != -1)
            return dp[sum];

        int taken = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            taken += f(sum - arr[i], arr, dp);
        }
        return dp[sum] = taken;
    }

    int combinationSum4(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(k + 1, -1);
        return f(k, nums, dp);
    }
};
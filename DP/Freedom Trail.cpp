#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[102][102];
    int count_steps(int ringind, int i, int n)
    {
        int clock_wise = abs(i - ringind);
        int anti = n - clock_wise;

        return min(clock_wise, anti);
    }

    int solve(int ringind, int kind, string &ring, string &key)
    {
        if (kind == key.size())
            return 0;

        if (dp[ringind][kind] != -1)
            return dp[ringind][kind];

        int result = INT_MAX;

        for (int i = 0; i < ring.size(); i++)
        {
            if (ring[i] == key[kind])
            {

                int steps = 1 + count_steps(ringind, i, ring.size());

                int total_steps = steps + solve(i, kind + 1, ring, key);

                result = min(result, total_steps);
            }
        }

        return dp[ringind][kind] = result;
    }

    int findRotateSteps(string ring, string key)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, ring, key);
    }
};
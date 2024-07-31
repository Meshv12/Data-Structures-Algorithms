#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];
    int fun(int i, int rem, int maxh, vector<vector<int>> &books, int k)
    {
        if (i >= books.size())
        {
            return maxh;
        }

        if (dp[i][rem] != -1)
            return dp[i][rem];

        int keep = 1e9;
        if (books[i][0] <= rem)
        {
            int cc = max(maxh, books[i][1]);
            keep = fun(i + 1, rem - books[i][0], cc, books, k);
        }

        int skip = maxh + fun(i + 1, k - books[i][0], books[i][1], books, k);

        return dp[i][rem] = min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();

        memset(dp, -1, sizeof(dp));

        return fun(0, shelfWidth, 0, books, shelfWidth);
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Input:
2            <- Fixed starting Point
3 4
6 5 7
4 1 8 3      <- Variable ending Points

Output:
11
*/

// Memoization

int f(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[n - 1][j];

    if (dp[i][j] != -1)
        return dp[i][j];
    int d = triangle[i][j] + f(i + 1, j, triangle, n, dp);
    int dg = triangle[i][j] + f(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(d, dg);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, triangle, n, dp);
}

// Tabulation

int minimumPathSum(vector<vector<int>> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = arr[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = arr[i][j] + dp[i + 1][j];
            int dg = arr[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(d, dg);
        }
    }
    return dp[0][0];
}
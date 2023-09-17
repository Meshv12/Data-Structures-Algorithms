#include <bits/stdc++.h>
using namespace std;

// Memoization

int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return N * price[0];
    }

    if (dp[ind][N] != -1)
        return dp[ind][N];

    int notTake = 0 + f(ind - 1, N, price, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N)
    {
        take = price[ind] + f(ind, N - rodLength, price, dp);
    }

    return dp[ind][N] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    return f(n - 1, n, price, dp);
}

// Tabulation

int tabulation(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = N * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {

            int notTake = 0 + dp[ind - 1][N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
            {
                take = price[ind] + dp[ind][N - rodLength];
            }

            dp[ind][N] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}

// 1-D Array Space Optimization

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    for (int N = 0; N <= n; N++)
    {
        prev[N] = N * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {

            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
            {
                take = price[ind] + prev[N - rodLength];
            }

            prev[N] = max(take, notTake);
        }
    }
    return prev[n];
}
#include <bits/stdc++.h>
using namespace std;

/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.



Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
*/

const int INF = 1e9;

int dp[105][10005];

int f(int ind, int sum, vector<int> &arr)
{
    if (sum == 0)
        return 0;
    if (ind < 0 || sum < 0)
        return INF;

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int take = INF;
    if (arr[ind] <= sum)
        take = 1 + f(ind, sum - arr[ind], arr);
    int nottake = f(ind - 1, sum, arr);

    dp[ind][sum] = min(take, nottake);

    return dp[ind][sum];
}

int numSquares(int n)
{
    vector<int> arr;
    for (int i = 1; i * i <= n; i++)
        arr.push_back(i * i);

    memset(dp, -1, sizeof(dp));

    return f(arr.size() - 1, n, arr);
}
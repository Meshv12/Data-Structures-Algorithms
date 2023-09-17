#include <bits/stdc++.h> 
using namespace std;

/*
3
1 2 3
4
Sample Output 1:
4
Explanation For Sample Output 1:
We can make a change for the value V = 4 in four ways.
1. (1,1,1,1),
2. (1,1, 2), [One thing to note here is, (1, 1, 2) is same as that of (2, 1, 1) and (1, 2, 1)]
3. (1, 3), and
4. (2, 2)
*/

// Memoization

long f(int ind, int T, int *a, vector<vector<long>>& dp){
    if(ind == 0){
        if(T % a[0] == 0) return 1;
        return 0;
    }

    if(dp[ind][T] != -1) return dp[ind][T];

    long notTake = f(ind - 1, T, a, dp);
    long take = 0;
    if(a[ind] <= T){
        take = f(ind, T - a[ind], a, dp);
    } 

    return dp[ind][T] = take + notTake;
}

long countWaysToMakeChange(int *a, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, 0));
    return f(n-1, value, a, dp);
}

// Tabulation

long countWaysToMakeChange(int *a, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, 0));
    for(int T = 0; T<=value; T++){
        if(T%a[0] == 0) dp[0][T] = 1;
        else dp[0][T] = 0;
    }

    for(int ind = 1; ind<n; ind++){
        for(int T = 0; T <= value; T++){
            long notTake = dp[ind - 1][T];
            long take = 0;
            if(a[ind] <= T){
                take = dp[ind][T - a[ind]];
            } 

            dp[ind][T] = take + notTake;
        }
    }

    return dp[n-1][value];
}

// Space optimization

long countWaysToMakeChange(int *a, int n, int value)
{
    vector<long> cur(value+1, 0), prev(value+1, 0);
    for(int T = 0; T<=value; T++){
        if(T%a[0] == 0) prev[T] = 1;
        else prev[T] = 0;
    }

    for(int ind = 1; ind<n; ind++){
        for(int T = 0; T <= value; T++){
            long notTake = prev[T];
            long take = 0;
            if(a[ind] <= T){
                take = cur[T - a[ind]];
            } 

            cur[T] = take + notTake;
        }
        prev = cur;
    }

    return prev[value];
}
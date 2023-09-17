#include <bits/stdc++.h>
using namespace std;

// Memoization

int findWaysUtil(int ind, int sum, vector<int>& arr, vector<vector<int>> &dp){
    
    if(ind == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 || sum == arr[0]) return 1;
        return 0;
    }
        
    if(dp[ind][sum] != -1)
        return dp[ind][sum];
        
    int notTaken = findWaysUtil(ind-1,sum,arr,dp);

    int taken = 0;
    if(arr[ind]<=sum)
        taken = findWaysUtil(ind-1,sum-arr[ind],arr,dp);

    return dp[ind][sum]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}

// Tabulation

int tabulation(int arr[], int n, int sum)
{
    const int MOD = 1e9 + 7;
       
 vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
 
    // Initialize the dp array
    dp[0][0] = 1;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % MOD;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
 
    return dp[n][sum];
}

/*
n = 6, arr[] = {2, 3, 5, 6, 8, 10};
sum = 10;  

dp array look like

1 0 0 0 0 0 0 0 0 0 0 
1 0 1 0 0 0 0 0 0 0 0 
1 0 1 1 0 1 0 0 0 0 0 
1 0 1 1 0 2 0 1 1 0 1 
1 0 1 1 0 2 1 1 2 1 1 
1 0 1 1 0 2 1 1 3 1 2 
1 0 1 1 0 2 1 1 3 1 3 <-- This is ans..
*/
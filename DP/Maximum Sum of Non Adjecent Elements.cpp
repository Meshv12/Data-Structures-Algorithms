#include <bits/stdc++.h> 
using namespace std;
/*
Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
*/

int f(int ind, vector<int> &nums, vector<int> &dp){   //Memoization
    if(ind == 0) return nums[0];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + f(ind - 2, nums, dp);
    int nonPick = 0 + f(ind - 1, nums, dp);

    return dp[ind] = max(pick, nonPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1, -1);
    return f(n-1, nums, dp);
}

// Tabulation

int maximumNonAdjacentSuM(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1, 0);
    dp[0] = nums[0];

    for(int i = 0; i<n; i++){
        int pick  = nums[i];
        if(i>1) pick += dp[i-2];
        int nonPick = 0 + dp[i-1];

        dp[i] = max(pick, nonPick); 
    }
    
    return dp[n-1];
}
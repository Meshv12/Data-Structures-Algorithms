#include<bits/stdc++.h>
using namespace std;
/*
You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, 
return the number of possible ways (out of the kn total ways) to roll the dice, 
so the sum of the face-up numbers equals target. Since the answer may be too large, 
return it modulo 109 + 7.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
*/

int mod = 1000000007;
int f(int n, int k, int target, vector<vector<int>> &dp){
        if(target == 0) return (n == 0);
        if(n == 0 || target < 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        int ways = 0;
        for(int i = 1; i<=k; i++){
            ways = (ways + f(n-1, k, target - i, dp))%mod;
        }

        return dp[n][target] = (ways % mod);
    }

int diceThrows(int n, int k, int target) {
    vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
        return f(n, k, target, dp);
}
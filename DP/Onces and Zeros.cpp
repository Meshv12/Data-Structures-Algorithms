#include <bits/stdc++.h> 
using namespace std;

/*
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.



Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

*/
class Solution {
public:
    int f(int m, int n, int ind, vector<string>& strs,  vector<vector<vector<int>>> &dp){
        if(ind == strs.size() || m + n == 0) return 0;

        if(dp[m][n][ind] != -1) return dp[m][n][ind];

        auto s = strs[ind];
        int cnt0 = 0;
        for(auto it : s){
            if(it == '0') cnt0++;
        }
        int cnt1 = s.length() - cnt0;

        int take = -1e9;
        if(m >= cnt0 && n >= cnt1)
            take = 1 + f(m - cnt0, n-cnt1, ind + 1 ,strs, dp);

        int nottake = 0 + f(m, n, ind + 1, strs, dp);

        return dp[m][n][ind] = max(take, nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        return f(m, n, 0, strs, dp);
    }
};
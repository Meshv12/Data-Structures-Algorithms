#include <bits/stdc++.h> 
using namespace std;

/*Given an integer array arr, partition the array into (contiguous) subarrays of length
at most k. After partitioning, each subarray has their values changed to 
become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.
Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]*/


// Memoization  (Front DP)  Palindrom partition concept

int f(int i, int n, int k, vector<int>& arr, vector<int> &dp){
        if (i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int len = 0, maxel = -1e9;
        int max_partition = -1e9;
        for(int j = i; j < min(i+k, n); j++){    // i+k may exeed the value of array 
            len++;
            maxel = max(maxel, arr[j]);

            int partition = len*maxel + f(j+1, n, k, arr, dp);
            max_partition = max(max_partition, partition);
        }
        return dp[i] = max_partition;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return f(0, n, k, arr, dp);
    }
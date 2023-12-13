#include <bits/stdc++.h> 
using namespace std;

int f(int ind, bool prev_swapped, vector<int>& arr1, vector<int>& arr2, vector<vector<int>> &dp){
        if(ind == arr1.size()) return 0;
        if(dp[ind][prev_swapped] != -1) return dp[ind][prev_swapped];

        int prev1 = arr1[ind-1];
        int prev2 = arr2[ind-1];

        // Previously Swapped or not
        if(prev_swapped == 1){
            swap(prev1, prev2);
        }

        int swap = INT_MAX, not_swap = INT_MAX;

        // No Swap --> if sequence is incresing then no swap is needed
        if(arr1[ind] > prev1 && arr2[ind] > prev2){
            not_swap = 0 + f(ind + 1, 0, arr1, arr2, dp);
        }

        // Swap 
        if(arr1[ind] > prev2 && arr2[ind] > prev1){
            swap = 1 + f(ind + 1, 1, arr1, arr2, dp);
        }

        return dp[ind][prev_swapped] = min(swap, not_swap);

    }
    int minSwap(vector<int>& arr1, vector<int>& arr2) {
        arr1.insert(arr1.begin(), -1);
        arr2.insert(arr2.begin(), -1);
        vector<vector<int>> dp(arr1.size()+1, vector<int>(3, -1));
        return f(1, 0, arr1, arr2, dp);
    }
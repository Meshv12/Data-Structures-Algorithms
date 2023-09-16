#include <bits/stdc++.h> 
using namespace std;

// Memoization   --> TC ->O(N*K)   
//                   SC -> O(N*K) + O(N) // extra auxiliary space

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) {
        if(arr[0] == target) return true;
        return false;
    }
    if(dp[ind][target] != -1) return dp[ind][target];

    bool notPick = f(ind - 1, target, arr, dp);
    bool pick = false;
    if(arr[ind] <= target){
        pick = f(ind - 1, target-arr[ind], arr, dp);
    }

    return dp[ind][target] = notPick | pick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}



// Tabulation         TC -> O(N*K)
//                    SC -> O(N*K)   // no auxiliary space

bool tabulation(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    
    for(int i = 0; i<n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;                            // Base cases

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <=k; target++){

            bool notPick = dp[ind - 1][target];
            bool pick = false;
            if(arr[ind] <= target){
                pick = dp[ind - 1][target-arr[ind]];
            }

            dp[ind][target] = pick | notPick;

        }
    }
    return dp[n-1][k];
}



// Space Optimization  TC -> O(N*K)
//                     SC -> O(K)   // no auxiliary space



//                                                       1) Take only 1-D array instate of 2-D dp because we need only prev data not whole 2-D
bool function(int n, int k, vector<int> &arr) {       // 2) Put dp[ind] = cur & dp[ind-1] = prev
    vector<bool> prev(k+1, 0), cur(k+1, 0);           // 3) After every iteration (prev = cur)
    prev[0] = cur[0] = true;                          // Note : Take first row is true because at target == 0 (acc. to base case) whole 1-D is true
    prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <=k; target++){

            bool notPick = prev[target];
            bool pick = false;
            if(arr[ind] <= target){
                pick = prev[target-arr[ind]];
            }

            cur[target] = pick | notPick;

        }
        prev = cur;
    }
    return prev[k];
}
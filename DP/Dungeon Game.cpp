#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& arr, int m, int n, vector<vector<int>> &dp){
        if(i >= m || j >= n) return 1e9;
        if(i == m-1 && j == n-1){
            if(arr[m-1][n-1] >= 0) return dp[m-1][n-1] = 1;
            else 
                return dp[m-1][n-1] = abs(arr[m-1][n-1]) + 1;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int right = f(i, j+1, arr, m, n, dp);
        int down  = f(i+1, j , arr, m, n, dp);
        int need_health = min(right, down) - arr[i][j];

        if(need_health > 0) return dp[i][j] = need_health;    // need additional health 
        else return dp[i][j] = 1;                             // enough health
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, dungeon, m, n, dp);
    }
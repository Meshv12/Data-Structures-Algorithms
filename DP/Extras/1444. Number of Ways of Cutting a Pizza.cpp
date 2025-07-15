#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int dp[51][51][11];
    int mod = 1e9+7;

    int f(int i, int j, int k, vector<vector<int>> &apples, int n, int m){
        if(i >= n || j >= m) return 0;

        // only one way to cut
        if(k == 1){
            if(apples[i][j] >= 1) return 1;
            return 0;
        }

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int total = 0;

        for(int hori = i; hori<n; hori++){

            int lower_slice = apples[hori][j];
            int upper_slice = apples[i][j] - apples[hori][j];

            if(upper_slice >= 1 && lower_slice >= k-1){
                total = (total + f(hori, j, k-1, apples, n, m))%mod;
            }
        }

        for(int ver = j; ver<m; ver++){
            
            int left_slice = apples[i][j] - apples[i][ver];
            int right_slice = apples[i][ver];

            if(left_slice >= 1 && right_slice >= k-1){
                total = (total + f(i, ver, k-1, apples, n, m))%mod;
            }
        }

        return dp[i][j][k] = total;
    }

    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();
        memset(dp, -1, sizeof(dp));

        // make 2-D prefix
        vector<vector<int>> apples(n, vector<int>(m, 0));

        apples[n-1][m-1] = pizza[n-1][m-1] == 'A' ? 1 : 0;

        for(int j = m-2; j >= 0; j--){
            apples[n-1][j] = pizza[n-1][j] == 'A' ? 1 : 0;
            apples[n-1][j] += apples[n-1][j+1];
        }
        for(int i = n-2; i >= 0; i--){
            apples[i][m-1] = pizza[i][m-1] == 'A' ? 1 : 0;
            apples[i][m-1] += apples[i+1][m-1];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j>=0; j--){
                apples[i][j] = pizza[i][j] == 'A' ? 1 : 0;

                apples[i][j] += apples[i+1][j] + apples[i][j+1] - apples[i+1][j+1];
            }
        }

        return f(0, 0, k, apples, n, m);
    }
};
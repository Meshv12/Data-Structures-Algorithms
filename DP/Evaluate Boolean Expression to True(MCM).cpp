#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;

long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp){
    if(i > j) return 0;
    if(i == j){
        if(isTrue == true)
            return (exp[i] == 'T');
        else
            return (exp[i] == 'F');
    }
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    long long ways = 0;
    for(int k = i+1; k<=j-1; k = k+2){
        long long leftT = f(i, k-1, 1, exp, dp);
        long long leftF = f(i, k-1, 0, exp, dp);
        long long rightT = f(k+1, j, 1, exp, dp);
        long long rightF = f(k+1, j, 0, exp, dp);

        if(exp[k] == '&'){
            if(isTrue) ways = (ways + (leftT * rightT)%mod )%mod;
            else ways = (ways + (leftF * rightT)%mod + (leftT * rightF)%mod + (leftF * rightF)%mod )%mod;
        }
        else if(exp[k] == '|'){
            if(isTrue) ways = (ways + (leftF * rightT)%mod + (leftT * rightF)%mod + (leftT * rightT)%mod )%mod;
            else ways = (ways + (leftF * rightF)%mod) %mod;
        }
        else{
            if(isTrue) ways = (ways + (leftT * rightF)%mod + (leftF * rightT)%mod)%mod;
            else ways = (ways + (leftT * rightT)%mod + (leftF * rightF)%mod)%mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return f(0, n - 1 , 1, exp, dp);
}
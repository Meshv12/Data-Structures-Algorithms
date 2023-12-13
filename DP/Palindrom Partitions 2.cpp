#include<bits/stdc++.h>
using namespace std;

// Question : Find minimum number of partitions----

// MCM APPROCH (Better Approch)
bool isPalindrome(string &s,int i,int j){
	while(i<=j){
		if(s[i++] != s[j--])
			return false;
	}
	return true;
}

int f(int i,int j, string &s, vector<vector<int>> &dp){
   if(i>=j)
   	return 0;
   if(isPalindrome(s,i,j))
   	return 0;
   if(dp[i][j] != -1) return dp[i][j];

   int mini = INT_MAX;
   for(int k=i;k<=j-1;k++){
        int temp = 1 + f(i, k, s, dp) + f(k+1, j, s, dp);
        mini = min(mini, temp);
   }

   return dp[i][j] = mini;
}
int palindromePartitioning(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return f(0, n-1, str, dp);
}


// Best Approch (Optimal) --> Front DP Concept 
// Memoization
bool isPalindroms(int i, int j, string &str){
    while(i < j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int f(int i, int n, string &str){
    if(i == n) return 0;

    int miniCost = INT_MAX;
    for(int k = i; k < n; k++){
        if(isPalindroms(i, k, str)){
            int cost = 1 + f(k+1, n, str);
            miniCost = min(miniCost, cost);
        }
    }
    return miniCost;
}

int palindromePartitioning(string str)
{
    int n = str.length();
    return f(0, n, str) - 1;
}

// Tabulation

int palindromePartitioning2(string str)
{
    int n = str.length();
    vector<int> dp(n+1, 0);

    for(int i = n-1; i>=0; i--){
        int miniCost = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalindroms(i, j, str)){
                int cost = 1 + dp[j+1];
                miniCost = min(miniCost, cost);
            }
        }
        dp[i] = miniCost;
    }
    return dp[0] - 1;
}
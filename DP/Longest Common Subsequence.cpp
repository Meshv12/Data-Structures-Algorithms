#include<bits/stdc++.h>
using namespace std;

// Memoization
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
	if(i == 0 || j == 0) return 0;

	if(dp[i][j] != -1) return dp[i][j];
	if(s[i-1] == t[j-1]){
		return dp[i][j] = 1 + f(i - 1, j - 1, s, t, dp);
	}
	return dp[i][j] = max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
}
int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	return f(n, m, s, t, dp);
}

// Tabulation

int tabulation(string s, string t)
{
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));    // Index shifting
	for(int i = 0; i<=n; i++) dp[i][0] = 0;
	for(int j = 0; j<=m; j++) dp[0][j] = 0;

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){

			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
        }
    }
	return dp[n][m];


// Print LCS
    /*
    int len = d[n][m];
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += '$';
    }
    int ind = len - 1;

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[ind] = s[i - 1];
            ind--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }

    cout << ans;
    */
}

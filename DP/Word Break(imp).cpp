#include <bits/stdc++.h>
using namespace std;

unordered_set<string> st;
int dp[301];
bool solve(int ind, string s)
{
    int n = s.size();
    if (ind == n)
        return true;

    if (st.find(s.substr(ind)) != st.end())
    {
        return dp[ind] = true;
    }

    if (dp[ind] != -1)
        return dp[ind];

    for (int k = 1; k <= n; k++)
    {
        string temp = s.substr(ind, k);

        if (st.find(temp) != st.end() && solve(ind + k, s))
        {
            return dp[ind] = true;
        }
    }
    return dp[ind] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    for (auto it : wordDict)
    {
        st.insert(it);
    }
    memset(dp, -1, sizeof(dp));

    return solve(0, s);
}
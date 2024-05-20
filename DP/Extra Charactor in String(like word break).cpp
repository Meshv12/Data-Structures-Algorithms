#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_set<string> st;
    int dp[51];

    int solve(int ind, string s)
    {
        int n = s.size();
        if (ind == s.size())
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int min_extra = INT_MAX;
        string temp = "";
        for (int k = ind; k < n; k++)
        {
            temp += s[k];

            int curr_extra = (st.find(temp) == st.end()) ? temp.size() : 0; // if word not find we have to include temp.size() new extra words

            int next_extra = solve(k + 1, s);

            int total_extra = curr_extra + next_extra;

            min_extra = min(min_extra, total_extra);
        }

        return dp[ind] = min_extra;
    }

    int minExtraChar(string s, vector<string> &dictionary)
    {
        for (auto it : dictionary)
        {
            st.insert(it);
        }
        memset(dp, -1, sizeof(dp));

        return solve(0, s);
    }
};
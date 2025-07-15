#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, bool> dp;
    bool solve(string s1, string s2)
    {
        if (s1 == s2)
        {
            return true;
        }

        if (s1.length() != s2.length())
            return false;

        string key = s1 + '_' + s2;
        if (dp.find(key) != dp.end())
            return dp[key];

        int n = s1.size();
        bool result = false;

        for (int i = 1; i < n; i++)
        {

            /*
                not swapped:  s1 = great    s2 = eatgr
                i = 2;
                s1.substr(0, i) = gr       s2.substr(0, i) = ea
                s1.substr(i, n-i) = eat    s2.substr(i, n-i) = tgr
            */

            bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n - i), s2.substr(i, n - 1));

            if (not_swapped == true)
            {
                result = true;
                break;
            }

            /*
                swapped:  s1 = great    s2 = eatgr
                i = 1;
                s1.substr(0, i) = gr       s2.substr(n-i, i) = ea
                s1.substr(i, n-i) = eat    s2.substr(0, n-i) = tgr
            */

            bool swapped = solve(s1.substr(0, i), s2.substr(n - i, i)) && solve(s1.substr(i, n - i), s2.substr(0, n - i));

            if (swapped == true)
            {
                result = true;
                break;
            }
        }

        return dp[key] = result;
    }

    bool isScramble(string s1, string s2)
    {
        return solve(s1, s2);
    }
};
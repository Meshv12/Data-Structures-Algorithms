#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;

    vector<string> addOperators(string s, int target)
    {
        helper(s, target, 0, "", 0, 0);
        return ans;
    }
    void helper(string s, int target, int i, const string &path, long eval, long residual)
    {
        if (i == s.length())
        {
            if (eval == target)
            {
                ans.push_back(path);
                return;
            }
        }
        string currStr;
        long num = 0;

        for (int j = i; j < s.length(); j++)
        {
            // handle 0
            if (j > i && s[i] == '0')
                return;

            currStr += s[j];
            num = num * 10 + s[j] - '0';
            if (i == 0)
            {
                helper(s, target, j + 1, path + currStr, num, num);
            }
            else
            {
                helper(s, target, j + 1, path + "+" + currStr, eval + num, num);
                helper(s, target, j + 1, path + "-" + currStr, eval - num, -num);
                helper(s, target, j + 1, path + "*" + currStr, (eval - residual) + (residual * num), residual * num);
            }
        }
    }
};
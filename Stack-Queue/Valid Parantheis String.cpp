#include <bits/stdc++.h>
using namespace std;

// Method : Onces Traverse left to right and then right to left if both counts are + then valid
// TC: O(N)
class Solution
{
public:
    bool checkValidString(string s)
    {
        int open = 0;
        int close = 0;
        int n = s.length();

        // Left to Right - Check Open Brackets
        for (int i = 0; i < n; i++)
        {

            if (s[i] == '(' || s[i] == '*')
            {
                open++;
            }
            else
            {
                open--;
            }

            if (open < 0)
            {
                return false;
            }
        }

        // Right to Left - Check CLose Brackets
        for (int i = n - 1; i >= 0; i--)
        {

            if (s[i] == ')' || s[i] == '*')
            {
                close++;
            }
            else
            {
                close--;
            }

            if (close < 0)
            {
                return false;
            }
        }

        return true;
    }
};

// METHOD : USING DP (*) have 3 options

int t[101][101];
bool solve(int idx, int open, string &s, int n)
{
    if (idx == n)
    {
        return open == 0;
    }

    if (t[idx][open] != -1)
    {
        return t[idx][open] == 1 ? true : false;
    }

    bool isValid = false;

    if (s[idx] == '*')
    {
        if (open > 0)
            isValid |= solve(idx + 1, open - 1, s, n); // Treating * as )

        isValid |= solve(idx + 1, open + 1, s, n); // Treating * as (

        isValid |= solve(idx + 1, open, s, n); // Treating * as ''
    }
    else if (s[idx] == '(')
    {
        isValid |= solve(idx + 1, open + 1, s, n);
    }
    else if (open > 0)
    {
        isValid |= solve(idx + 1, open - 1, s, n);
    }

    return t[idx][open] = isValid;
}

bool checkValidString(string s)
{
    int n = s.length();
    memset(t, -1, sizeof(t));
    return solve(0, 0, s, n);
}

// METHOD 3: TWO STACKS : FOR parentasis and for astrics

bool checkValidString(string s)
{
    stack<int> openSt;
    stack<int> asterisksSt;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(')
        {
            openSt.push(i);
        }
        else if (ch == '*')
        {
            asterisksSt.push(i);
        }
        else
        {
            if (!openSt.empty())
            {
                openSt.pop();
            }
            else if (!asterisksSt.empty())
            {
                asterisksSt.pop();
            }
            else
            {
                return false;
            }
        }
    }

    // This post processing will be required for cases like - "*(())(*"
    while (!openSt.empty() && !asterisksSt.empty())
    {
        if (openSt.top() > asterisksSt.top())
        {
            return false;
        }
        openSt.pop();
        asterisksSt.pop();
    }

    return openSt.empty();
}
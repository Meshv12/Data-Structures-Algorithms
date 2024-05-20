#include <bits/stdc++.h>
using namespace std;

// using pick not pick

class Solution
{
public:
    bool check(string str1, string str2)
    {
        vector<int> freq(26, 0);
        for (auto it : str1)
        {
            if (freq[it - 'a'] > 0)
                return true;
            freq[it - 'a']++;
        }
        for (auto it : str2)
        {
            if (freq[it - 'a'] > 0)
                return true;
            freq[it - 'a']++;
        }
        return false;
    }

    unordered_map<string, int> mp;

    int f(int i, string temp, vector<string> &arr)
    {
        if (i == arr.size())
            return temp.size();

        if (mp.find(temp) != mp.end())
            return mp[temp];

        int exclude = 0;
        int include = 0;

        if (check(arr[i], temp))
        {
            exclude = f(i + 1, temp, arr);
        }
        else
        { // there are unique chars then we have 2 options
            exclude = f(i + 1, temp, arr);
            include = f(i + 1, temp + arr[i], arr);
        }
        return mp[temp] = max(exclude, include);
    }
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        string temp = "";
        mp.clear();

        return f(0, temp, arr);
    }
};

// using bit manipulation (no need to check function)

class Solution
{
public:
    int f(int i, int temp, vector<string> &arr, vector<int> &uniquestr)
    {
        if (i == uniquestr.size())
        {
            return __builtin_popcount(temp);
        }

        int exclude = 0;
        int include = 0;

        if ((temp & uniquestr[i]) != 0)
        {
            exclude = f(i + 1, temp, arr, uniquestr);
        }
        else
        { // there are unique chars then we have 2 options
            exclude = f(i + 1, temp, arr, uniquestr);
            include = f(i + 1, temp | uniquestr[i], arr, uniquestr);
        }
        return max(exclude, include);
    }

    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        string temp = "";
        vector<int> uniquestr;

        for (auto it : arr)
        {
            unordered_set<char> st(it.begin(), it.end());

            if (st.size() != it.size())
                continue;

            int string_to_bit = 0;

            for (auto ch : it)
            {
                string_to_bit |= 1 << (ch - 'a');
            }

            uniquestr.push_back(string_to_bit);
        }

        return f(0, 0, arr, uniquestr);
    }
};
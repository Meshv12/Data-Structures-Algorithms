#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> shortestSubstrings(vector<string> &arr)
    {
        vector<string> ans;

        unordered_map<string, int> mp;

        // Find all Substr
        for (auto it : arr)
        {

            unordered_set<string> st;

            for (int i = 0; i < it.size(); i++)
            {
                for (int j = i + 1; j <= it.size(); j++)
                {

                    string str = it.substr(i, j - i);
                    if (st.find(str) == st.end())
                    {
                        mp[str]++;
                        st.insert(str);
                    }
                }
            }
        }

        for (auto it : arr)
        {

            string shortest = "";

            for (int i = 0; i < it.size(); i++)
            {
                for (int j = i + 1; j <= it.size(); j++)
                {

                    string str = it.substr(i, j - i);

                    if (mp[str] == 1 && (shortest == "" || str.size() < shortest.size() || (str.size() == shortest.size() && str < shortest)))
                    {
                        shortest = str;
                    }
                }
            }

            ans.push_back(shortest);
        }

        return ans;
    }
};
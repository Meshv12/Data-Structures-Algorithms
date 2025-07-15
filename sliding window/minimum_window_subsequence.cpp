#include <bits/stdc++.h>;
using namespace std;

int n, m;

int f(int i, int j, string &s, string &t)
{
    if (j >= m)
        return 0;
    if (j < m && i >= n)
        return 1e9;

    int a = 1e9, b = 1e9;

    if (s[i] == t[j])
        a = 1 + f(i + 1, j + 1, s, t);
    else
    {
        b = 1 + f(i + 1, j, s, t);
    }

    return min(a, b);
}

string minWindow(string s, string t)
{
    n = s.size();
    m = t.size();
    int starting_ind = -1, ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[0])
        {
            int z = f(i, 0, s, t);

            if (z < ans)
            {
                ans = z;
                starting_ind = i;
            }
        }
    }

    // cout<<starting_ind<<" "<<ans;
    if (starting_ind == -1)
        return "";
    return s.substr(starting_ind, ans);
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> res;

    void solve(int i, int j, vector<vector<int>> &m, int n, string s)
    {
        if (i == n - 1 && j == n - 1 && m[i][j] == 1)
        {
            res.push_back(s);
            return;
        }
        if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] == 0)
            return;

        m[i][j] = 0;

        s.push_back('L');
        solve(i, j - 1, m, n, s);
        s.pop_back();

        s.push_back('U');
        solve(i - 1, j, m, n, s);
        s.pop_back();

        s.push_back('D');
        solve(i + 1, j, m, n, s);
        s.pop_back();

        s.push_back('R');
        solve(i, j + 1, m, n, s);
        s.pop_back();

        m[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        string s;

        solve(0, 0, m, n, s);

        return res.size() > 0 ? res : vector<string>{"-1"};
    }
};
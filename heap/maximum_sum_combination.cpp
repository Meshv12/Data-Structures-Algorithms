#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b)
    {
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        priority_queue<vector<int>> pq;
        pq.push({a[0] + b[0], 0, 0});
        set<pair<int, int>> st;
        st.insert({0, 0});

        vector<int> ans;

        while (k--)
        {
            int sum = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();

            ans.push_back(sum);

            if (j + 1 < n && st.find({i, j + 1}) == st.end())
            {
                pq.push({a[i] + b[j + 1], i, j + 1});
                st.insert({i, j + 1});
            }
            if (i + 1 < n && st.find({i + 1, j}) == st.end())
            {
                pq.push({a[i + 1] + b[j], i + 1, j});
                st.insert({i + 1, j});
            }
        }

        return ans;
    }
};
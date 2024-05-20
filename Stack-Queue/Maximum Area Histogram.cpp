#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> &arr)
{
    int n = arr.size();
    stack<pair<int, int>> st;
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {

        if (st.empty())
            ans.push_back(-1);
        else if (st.size() > 0 && st.top().first < arr[i])
        {
            ans.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
                st.pop();

            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top().second);
        }

        st.push({arr[i], i});
    }

    return ans;
}

vector<int> NSR(vector<int> &arr)
{
    int n = arr.size();
    stack<pair<int, int>> st;
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {

        if (st.empty())
            ans.push_back(n);
        else if (st.size() > 0 && st.top().first < arr[i])
        {
            ans.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
                st.pop();

            if (st.empty())
                ans.push_back(n);
            else
                ans.push_back(st.top().second);
        }

        st.push({arr[i], i});
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> left;
    vector<int> right;

    left = NSL(heights);
    right = NSR(heights);
    reverse(right.begin(), right.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }

    return ans;
}
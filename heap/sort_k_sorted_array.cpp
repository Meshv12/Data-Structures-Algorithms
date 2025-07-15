#include <bits/stdc++.h>
using namespace std;

vector<int> nearlySorted(vector<int> nums, int n, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq; // use k size min heap for put smallest ele

    for (int i = 0; i <= k - 1; i++)
    {
        pq.push(nums[i]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (i + k < n)
            pq.push(nums[i + k]);
        ans[i] = pq.top();
        pq.pop();
    }

    return ans;
}
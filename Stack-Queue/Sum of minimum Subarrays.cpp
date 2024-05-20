#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    ll mod = 1e9 + 7;

    vector<int> getNSL(vector<int> &arr, int n)
    {
        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                res[i] = -1;
            }
            else
            {
                while (!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();

                res[i] = st.empty() ? -1 : st.top();
            }

            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int> &arr, int n)
    {
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                res[i] = n;
            }
            else
            {
                while (!st.empty() && arr[st.top()] > arr[i])
                    st.pop();

                res[i] = st.empty() ? n : st.top();
            }

            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll left = i - NSL[i];
            ll right = NSR[i] - i;

            ll total_ways = left * right;
            ll cc = total_ways * arr[i];

            ans = (ans + cc) % mod;
        }

        return ans;
    }
};
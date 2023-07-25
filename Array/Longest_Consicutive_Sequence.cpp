#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)       // O(n)
    {
        st.insert(a[i]);
    }

    for (auto it : st) // O(n+n) not O(n^2)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) // It's unorderd set so it's take O(1) time for best and avg case.
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        } //  It skiped elements which not stared from starting
          //  1,2,4,3,102,101,100   // it skip 2,3,4,102,102 bcz it not start from starting
    }

    return longest; // Space O(n) bcz of unorderd set
}

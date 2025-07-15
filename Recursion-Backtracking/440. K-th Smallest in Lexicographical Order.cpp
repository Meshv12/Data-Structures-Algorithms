#include <bits/stdc++.h>
using namespace std;

// TC : O(log N)

// Its a tree structure (either goes down or goes right)

 
class Solution
{
public:
    typedef long long ll;

    ll count_on_current_lvl(ll curr, ll next, int n)
    {

        ll tot = 0;
        while (curr <= n)
        {
            tot += (next - curr);

            curr *= 10;
            next *= 10;

            next = min(next, (ll)n + 1);
        }

        return tot;
    }

    int findKthNumber(int n, int k)
    {
        ll curr = 1;
        k--;

        while (k > 0)
        {
            ll cnt = count_on_current_lvl(curr, curr + 1, n);

            if (cnt <= k)
            {                                  // move to next node on same lvl
                curr = curr + 1;
                k = k - cnt;
            }
            else
            {                                 // deep dive on same sub tree
                curr = curr * 10;
                k--;
            }
        }

        return curr;
    }
};
#include <bits/stdc++.h>
using namespace std;

// O(N) TC    O(1) SC
// Josephus problem

class Solution
{
public:
    int solve(int n, int k)
    {
        if (n == 1)
            return 0; // only one element left so return its ind

        int ind = solve(n - 1, k);
        ind = (ind + k) % n; // to find ind of original array

        return ind;
    }

    int findTheWinner(int n, int k)
    {
        return solve(n, k) + 1;
    }
};
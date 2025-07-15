#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &q)
    {
        int n = nums.size();

        // store ending ind
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> past;

        sort(q.begin(), q.end());

        int j = 0; // for traverse in queries
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {

            while (j < q.size() && q[j][0] == i)
            {
                pq.push(q[j][1]);
                j++;
            }

            while (!past.empty() && past.top() < i)
            {
                past.pop();
            }

            nums[i] -= past.size();
            if (nums[i] <= 0)
                continue; // become zero using prev queries

            while (!pq.empty() && nums[i] > 0)
            {
                int fartherest = pq.top();
                pq.pop();

                if (fartherest < i)
                    break; // we will skip that bcz can't affect our element right now

                nums[i]--;
                past.push(fartherest);
                cnt++;
            }

            if (nums[i] > 0)
                return -1;
        }

        return q.size() - cnt;
    }
};
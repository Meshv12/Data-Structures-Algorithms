#include <bits/stdc++.h>
using namespace std;

struct ComparePairs
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        // Compare based on the first element
        if (p1.first != p2.first)
        {
            return p1.first > p2.first; // Min heap based on the first element
        }
        else
        {
            return p1.second > p2.second; // If first elements are equal, compare based on the second element
        }
    }
};

class Solution
{
public:
    typedef long long ll;
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> end_time;
        priority_queue<int, vector<int>, greater<int>> rooms;
        vector<int> mp(n, 0);
        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < n; i++)
            rooms.push(i);

        for (auto it : meetings)
        {
            ll duration = it[1] - it[0];

            while (end_time.size() > 0 && end_time.top().first - it[0] <= 0)
            {
                auto r = end_time.top().second;
                end_time.pop();

                rooms.push(r);
            }

            if (rooms.size() > 0)
            {
                int r = rooms.top();
                rooms.pop();
                end_time.push({it[1], r});

                mp[r]++;
            }
            else
            {
                int tt = end_time.top().first - it[0];

                int r = end_time.top().second;
                ll endTime = end_time.top().first;
                end_time.pop();
                end_time.push({endTime + duration, r});
                mp[r]++;
            }
        }

        int maxi = 0;
        int max_ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[i] > maxi)
            {
                maxi = mp[i];
                max_ind = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << mp[i] << " ";
        }
        cout << endl;

        return max_ind;
    }
};
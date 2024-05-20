#include <bits/stdc++.h>
using namespace std;

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    priority_queue<int> pq;
    int n = heights.size();

    int i;
    for (i = 0; i < n - 1; i++)
    {

        int diff = heights[i + 1] - heights[i];

        if (diff <= 0)
        { // next building is small -> just jump
            continue;
        }

        if (diff <= bricks)
        {
            bricks -= diff;
            pq.push(diff); // store used bricks for future
        }
        else if (ladders > 0)
        {

            if (!pq.empty())
            { // I have ladder and use bricks in past but not enough bricks this time

                int max_past_bricks = pq.top();

                if (max_past_bricks > diff)
                {
                    bricks += max_past_bricks;
                    bricks -= diff;

                    pq.pop();
                    pq.push(diff);
                    ladders--;
                }
                else
                    ladders--;
            }
            else
                ladders--; // I have ladder and  not use bricks in past but not enough bricks this time
        }
        else
        {
            break; // i havnot enough ladders and bricks
        }
    }

    return i;
}
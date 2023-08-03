#include <bits/stdc++.h>
/*Sample Input 1 : 6 4 0 3 4 7 10 9

    Sample Output 1 : 3

    Explanation To Sample Input 1 : 
    The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions{0, 3, 7, 10}.
    Here distance between cows are 3,
    4 and 3 respectively.using namespace std;  */

using namespace std;
bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int totalcows = 1, lastposition = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastposition >= dist)
        {
            totalcows++;
            lastposition = stalls[i];
        }
    }
    if (totalcows >= cows)
        return true;
    else
        return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
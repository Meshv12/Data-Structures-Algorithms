#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size();
    int Presum = 0, cnt = 0;
    map<int, int> mpp;
    mpp[0] = 1; // Hash map < presum , cnt >

    for (int i = 0; i < n; i++)
    {
        Presum = Presum + arr[i];
        int rem = Presum - k;
        cnt = cnt + mpp[rem];
        mpp[Presum]++;
    }
    return cnt;
}
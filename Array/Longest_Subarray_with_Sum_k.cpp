#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    map<long long int, int> hashmpp;
    int n = a.size();
    long long int sum = 0;
    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i]; // calculating prefix sum
        if (sum == k)
        {
            maxlen = max(maxlen, i + 1);
        }

        long long int rem = sum - k; // it is similer to x-k...

        if (hashmpp.find(rem) != hashmpp.end())
        {
            int len = i - hashmpp[rem];
            maxlen = max(maxlen, len);
        }

        if (hashmpp.find(sum) == hashmpp.end()) // this condition for zeros and negetives . We need
        {                                       // unique prefix sum if same then not consider(as much as push left and make longest subarray)
            hashmpp[sum] = i;
        }
    }
    return maxlen;
}

// For only postitives

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int n = a.size();
    long long int sum = a[0];
    int maxLen = 0;
    int left = 0, right = 0;
    while (right < n)
    {

        while (left <= right && sum > k)
        {
            sum = sum - a[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        sum += a[right];
    }

    return maxLen;
}
#include <bits/stdc++.h>
using namespace std;

// Hashing Method (Better Approch)
vector<int> findMissingRepeatingNumbers(vector<int> arr)
{
    int n = arr.size();
    int hash[n + 1] = {0}; //                   TC --> O(N)
    for (int i = 0; i < n; i++)
    { //                                        SC --> O(N)  // Need to optimal
        hash[arr[i]]++;
    }
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            repeating = i;
        else if (hash[i] == 0)
            missing = i;

        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {repeating, missing};
}

// Optimal Approch

vector<int> findMissingRepeatingNumbers(vector<int> arr)
{
    long long n = arr.size();
    // S -Sn = x - y
    // S2 - S2n
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = S - SN; // x - y
    long long val2 = S2 - S2N;
    val2 = val2 / val1; // divide by X - Y

    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}
#include <bits/stdc++.h>
using namespace std;

/*
Sample Input 1:
5
1 2 3 4 5
8

Sample Output 1:
3

Explanation For Sample Input 1:
We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor.
The sum is 9(1 + 1 + 2 + 2 + 3) if we choose 2 as a divisor, and the sum is 7(1 + 1 + 1 + 2 + 2) if we choose 3 as a divisor, which is less than the 'limit'.
Hence, we return 3.
*/

int sumByD(vector<int> &arr, int div)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + ceil((double)arr[i] / (double)div);
    }
    return sum;
}
int smallestDivisor(vector<int> &arr, int limit)
{
    int n = arr.size();
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
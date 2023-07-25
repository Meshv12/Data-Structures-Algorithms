#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0, maxi = LONG_MIN;
    long long start=0 , ansStart=-1,ansEnd=-1;
    for(int i =0; i<n; i++)
    {
        // if(sum==0) start = i;        for printing longest subarray

        sum = sum + arr[i];

        if(sum > maxi)
        {
            maxi = sum;
            //ansStart = start;       for printing longest subarray
            //ansEnd = i;
        }
        if(sum<0)
        {
            sum = 0;
        }
    }
    if(maxi < 0) maxi = 0;
    return maxi;
}
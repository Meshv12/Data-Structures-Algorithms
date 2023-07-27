#include <bits/stdc++.h>
using namespace std;
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &nums1, vector<long long> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

// Gap Method (Use in shell sort)

void swapIfGreater(vector<long long> &nums1, vector<long long> &nums2, int ind1, int ind2)
{
    if (nums1[ind1] > nums2[ind2])
    {
        swap(nums1[ind1], nums2[ind2]);
    }
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &nums1, vector<long long> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int len = n + m;
    int gap = (len + 1) / 2; // Update gap calculation    //Formula for gap method (ceil value)

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < len)
        {

            if (left < n && right < n)
            { //                                         Left pointer in arr1 and Right pointer also in arr1
                swapIfGreater(nums1, nums1, left, right);
            }
            else if (left < n && right >= n)
            { //                                         Left pointer in arr1 and Right pointer in arr2
                swapIfGreater(nums1, nums2, left, right - n);
            }
            else if (left >= n && right >= n)
            { //                                         Left pointer in arr2 and Right pointer also in arr2
                swapIfGreater(nums2, nums2, left - n, right - n);
            }
            right++;
            left++;
        }

        if (gap == 1)
            break;

        gap = (gap + 1) / 2; // Update gap calculation
    }
}

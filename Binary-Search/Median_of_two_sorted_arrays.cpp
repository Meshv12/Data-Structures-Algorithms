#include <bits/stdc++.h>
using namespace std;

/**
 * Calculates the median of two sorted arrays.
 * 
 *  a The first sorted array.
 *  b The second sorted array.
 *  The median of the combined arrays.
 */

double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();

    // Ensuring n1 is the smaller array to simplify calculations
    if (n1 > n2)
        return median(b, a);

    int low = 0, high = n1;
    int left_elements = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left_elements - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        // Handling array bounds
        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        // Checking for median condition
        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1)
                return max(l1, l2);
            else {
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
        } 
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }

    return 0; // Default case when no median is found
}
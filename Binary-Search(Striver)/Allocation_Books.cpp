/*
Sample Input 1:
4 2
12 34 67 90


Sample Output 1:
113


Explanation Of Sample Input 1:
All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
*/

#include<bits/stdc++.h>
using namespace std;
int countStudents(vector<int> &arr, int pages)
{
    int students = 1;
    long long totalpages = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (totalpages + arr[i] <= pages)
        {
            totalpages = totalpages + arr[i];
        }
        else
        {
            students++;
            totalpages = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
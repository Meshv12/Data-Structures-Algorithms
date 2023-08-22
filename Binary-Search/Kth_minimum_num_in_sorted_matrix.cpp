#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int check(vector<vector<int>> &mat, int mid, int n, int m) // O(n + m) for cnt
    {
        int cnt = 0;
        int row = 0, col = m - 1;

        while (row < n && col >= 0)
        { // howmany nums smaller than mid in rows and cols sorted matrix
            if (mat[row][col] > mid)
            {
                col--;
            }
            else
            {
                cnt = cnt + col + 1;
                row++;
            }
        }

        return cnt;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int cnt = check(matrix, mid, n, m); // black box give how many nums smaller than mid(rank of mid in matrix)
            if (cnt < k)
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
};

// TC --> O(log(max_ele)*(n + m))

// Using Priority queue

class solution2
{

    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> pq; //    O(n*m*log(k))

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};

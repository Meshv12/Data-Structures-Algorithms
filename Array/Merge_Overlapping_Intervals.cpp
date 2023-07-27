#include <bits/stdc++.h>
using namespace std;

//Better Approch

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
	int n = arr.size();
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
	{
		int start = arr[i][0];
		int end = arr[i][1];

		if (!ans.empty() && end <= ans.back()[1])
		{
			continue;
		}

		for (int j = i + 1; j < n; j++)
		{ // TC --> O(2*N) not O(N^2)  show in book
			if (arr[j][0] <= end)
			{ //  we can modify to only one travesal in vector
				end = max(end, arr[j][1]);
			}
			else
			{
				break;
			}
		}

		ans.push_back({start, end});
	}

	return ans;
}

// Optimal Approch

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
	int n = arr.size();
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		if (ans.empty() || arr[i][0] > ans.back()[1])
		{ //                                                          O(N) only one travasal
			ans.push_back({arr[i][0], arr[i][1]});
		}
		else
		{
			ans.back()[1] = max(ans.back()[1], arr[i][1]);
		}
	}

	return ans;
}

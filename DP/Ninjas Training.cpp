#include<bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {

  // Args:
  //   day: The current day.
  //   last: The last task performed.
  //   points: A 2D array of points, where `points[day][task]` is the number of points earned by performing task `task` on day `day`.
  //   dp: A 2D array of memoization values, where `dp[day][last]` stores the maximum points that can be earned in the next `day` days, given that the last task performed was `last`.

  // Returns:
  //   The maximum points that can be earned in the next `day` days, given that the last task performed was `last`.

  // Base case: if it is the first day, we can only earn the points for the first task.
  if (day == 0) {
    int maxi = 0;
    for (int task = 0; task < 3; task++) {
      if (task != last) {
        maxi = max(maxi, points[0][task]);
      }
    }
    return maxi;
  }

  // This comment checks if the value has already been calculated.
  if(dp[day][last] != -1) return dp[day][last];

  // Recursively calculate the maximum points possible for all the other tasks.
  // This comment explains the recursive call.
  int maxi = 0;
  for (int task = 0; task < 3; task++) {
    if (task != last) {
      int point = points[day][task] + f(day - 1, task, points, dp);
      maxi = max(maxi, point);
    }
  }

  return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
 
  vector<vector<int>> dp(n, vector<int>(4, -1));
  return f(n - 1, 3, points, dp);
}

int tabulation(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));


    for(int day = 1; day<n; day++){
        for(int last = 0; last < 4; last++){

// This part is same as memoization 

            dp[day][last] = 0;
            int maxi = 0;


            for(int task = 0; task<3; task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    maxi = max(maxi, point);
                }
            }

            dp[day][last] = maxi;

// till here
        }
    }
    return dp[n-1][3];
}

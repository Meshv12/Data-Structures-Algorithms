#include <bits/stdc++.h>
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
      int n = days.size();
      int lastDay = days[n-1];

      set<int> st;
      for(auto it: days) st.insert(it);

      vector<int> dp(lastDay + 1, 0);
      dp[0] = 0;
      
      for(int day = 1; day <= lastDay; day++){
          if(st.find(day) == st.end()){
              dp[day] = dp[day-1];
              continue;
          }

          dp[day] = min({dp[day - 1] + costs[0],   dp[max(0, day - 7)] + costs[1],   dp[max(0, day - 30)] + costs[2]});

      }
      return dp[lastDay];
}
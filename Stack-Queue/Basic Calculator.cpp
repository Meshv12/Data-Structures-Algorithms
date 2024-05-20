#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int n = s.size();
        stack<int> st;

        int number = 0;
        int result = 0;
        int sign = 1;

        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                number = number * 10 + (s[i] - '0');
            }
            else if (s[i] == '+')
            { // add number into result
                result += (number * sign);
                number = 0;
                sign = 1;
            }
            else if (s[i] == '-')
            {
                result += (number * sign);
                number = 0;
                sign = -1;
            }
            else if (s[i] == '(')
            { // push sign and res to stack
                st.push(result);
                st.push(sign);
                result = 0; // start new beginning for () elements
                number = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                result += (number * sign);
                number = 0; // bracket nu solve thai gayu

                int stack_sign = st.top();
                st.pop();
                int prev_result = st.top();
                st.pop();

                result = result * stack_sign;
                result += prev_result;
            }
        }
        result += (number * sign);
        return result;
    }
};
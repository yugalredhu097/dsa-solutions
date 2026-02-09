// Problem: Daily Temperatures
// Link: https://leetcode.com/problems/daily-temperatures/
// Approach: Monotonic Stack (Next Greater Element)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
For each day, we need to find how many days we must wait
until a warmer temperature occurs.

Approach:
1. Use a monotonic decreasing stack that stores indices.
2. Traverse the array from right to left.
3. For each index:
   - Pop elements from the stack while they are less than
     or equal to the current temperature.
   - The top of the stack gives the next warmer day.
4. Store the difference of indices as the result.

This ensures each element is pushed and popped at most once.
*/

class Solution {
public:
    void ngefunc(vector<int> &nge, vector<int> &temperatures) {
        stack<int> st;
        int n = temperatures.size();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                   temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if (st.empty())
                nge[i] = i;
            else
                nge[i] = st.top();

            st.push(i);
        }
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> nge(n);

        ngefunc(nge, temperatures);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(nge[i] - i);
        }

        return ans;
    }
};

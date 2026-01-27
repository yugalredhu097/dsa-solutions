// Problem: Largest Rectangle in Histogram (LeetCode 84)
// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Approach: Monotonic stack (Previous Smaller Element + Next Smaller Element)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
For each bar in the histogram, we want to find the largest rectangle
where this bar is the smallest height.

Steps:
1. Find Previous Smaller Element (PSE) for every bar.
2. Find Next Smaller Element (NSE) for every bar.
3. Width of rectangle for index i:
   = (nse[i] - pse[i] - 1)
4. Area = height[i] * width
5. Track the maximum area.
*/

class Solution {
public:
    void nsefunc(vector<int>& nse, vector<int>& heights) {
        stack<int> st;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty()) nse[i] = heights.size();
            else nse[i] = st.top();
            st.push(i);
        }
    }

    void psefunc(vector<int>& pse, vector<int>& heights) {
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse(n), pse(n);
        nsefunc(nse, heights);
        psefunc(pse, heights);

        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};

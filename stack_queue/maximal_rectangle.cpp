// Problem: Maximal Rectangle (LeetCode 85)
// Link: https://leetcode.com/problems/maximal-rectangle/
// Approach: Histogram + Monotonic Stack
// Time Complexity: O(n * m)
// Space Complexity: O(m)

/*
Explanation:
Each row of the matrix is treated as the base of a histogram.
For every row:
1. Build a histogram where height[j] is the count of consecutive '1's above.
2. Compute the largest rectangle in the histogram using:
   - Previous Smaller Element (PSE)
   - Next Smaller Element (NSE)
3. Track the maximum rectangle area over all rows.
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

    int histogram(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n), pse(n);

        nsefunc(nse, heights);
        psefunc(pse, heights);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            ans = max(ans, histogram(heights));
        }
        return ans;
    }
};

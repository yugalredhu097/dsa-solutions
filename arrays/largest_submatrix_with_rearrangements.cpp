// Problem: Largest Submatrix With Rearrangements
// Link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/
// Approach: Histogram Heights + Sorting
// Time Complexity: O(m * n log n)
// Space Complexity: O(n)

/*
Explanation:

We are given a binary matrix. We are allowed to rearrange
the columns of each row independently.

Goal:
Find the largest submatrix consisting entirely of 1s.

------------------------------------------------

Key Idea:

For every row we treat the matrix like a histogram.

1. Maintain an array `heights`:
   heights[j] represents the number of consecutive 1s
   ending at the current row for column j.

2. If matrix[i][j] == 1:
        heights[j]++
   else:
        heights[j] = 0

3. Since we can rearrange columns, we sort the heights
   in descending order.

4. After sorting, we calculate possible areas:
      area = height * width

   where:
      height = heights[i]
      width  = i + 1

5. Track the maximum area across all rows.

------------------------------------------------

Example:

Matrix:
0 0 1
1 1 1
1 0 1

Heights evolve row by row and after sorting
we compute possible rectangle areas.

The maximum possible rectangle of 1s is returned.
*/

class Solution {
public:

    int histogram(vector<int> heights) {

        sort(heights.rbegin(), heights.rend());

        int ans = 0;

        for (int i = heights.size() - 1; i >= 0; i--) {

            int area = heights[i] * (i + 1);

            ans = max(ans, area);
        }

        return ans;
    }

    int largestSubmatrix(vector<vector<int>>& matrix) {

        vector<int> heights(matrix[0].size(), 0);

        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {

            for (int j = 0; j < matrix[0].size(); j++) {

                if (matrix[i][j] == 1)
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            int area = histogram(heights);

            ans = max(ans, area);
        }

        return ans;
    }
};
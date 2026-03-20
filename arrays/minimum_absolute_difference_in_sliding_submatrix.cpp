// Problem: Minimum Absolute Difference in Sliding Submatrix
// Link: https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/
// Approach: Brute Force over k×k submatrices
// Time Complexity: O(n * m * k^4)
// Space Complexity: O(1)

/*
Explanation:

We are given a grid and an integer k.

Goal:
For every k × k submatrix, compute the minimum absolute
difference between any two distinct elements inside it.

------------------------------------------------

Approach:

1. Iterate over all possible k × k submatrices.
   Top-left corner ranges:
      i → 0 to (row - k)
      j → 0 to (col - k)

2. For each submatrix:
   - Compare every pair of elements
   - Compute absolute difference
   - Track the minimum

3. If all elements are equal,
   return 0 for that submatrix.

------------------------------------------------

Helper Function:

absmin(...) computes the minimum absolute difference
within a given submatrix.

------------------------------------------------

Note:

This is a brute-force solution.
Optimized solutions may use sorting or balanced structures
to reduce complexity.
*/

class Solution {
public:

    int absmin(vector<vector<int>> &g, int strow, int endrow, int stcol, int endcol) {

        int mini = INT_MAX;

        for (int i = strow; i <= endrow; i++) {

            for (int j = stcol; j <= endcol; j++) {

                for (int k = i; k <= endrow; k++) {

                    for (int l = stcol; l <= endcol; l++) {

                        if (g[i][j] != g[k][l])
                            mini = min(mini, abs(g[i][j] - g[k][l]));
                    }
                }
            }
        }

        return (mini == INT_MAX) ? 0 : mini;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i <= row - k; i++) {

            vector<int> temp;

            for (int j = 0; j <= col - k; j++) {

                temp.push_back(absmin(grid, i, i + k - 1, j, j + k - 1));
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
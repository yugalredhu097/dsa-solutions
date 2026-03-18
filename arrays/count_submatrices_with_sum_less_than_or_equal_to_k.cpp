// Problem: Count Submatrices With Top-Left Element and Sum Less Than or Equal to k
// Link: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-or-equal-to-k/
// Approach: 2D Prefix Sum
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

/*
Explanation:

We are given a grid and an integer k.

Goal:
Count the number of submatrices starting from (0,0)
whose total sum is less than or equal to k.

------------------------------------------------

Key Idea: 2D Prefix Sum

Instead of recalculating sums for every submatrix,
we build prefix sums to quickly compute the sum
of any rectangle from (0,0) to (i,j).

Steps:

1. Compute row-wise prefix sums.
   rowpref[i][j] = sum of elements from grid[i][0..j]

2. Convert this into a full 2D prefix sum:
   all[i][j] = sum of elements from grid[0..i][0..j]

3. Each cell (i,j) now represents the sum of
   the submatrix from (0,0) to (i,j).

4. Count how many of these sums are ≤ k.

Optimization:
Since values increase across columns, we break
early if the sum exceeds k.

------------------------------------------------

Example:

Grid:
1 2
3 4

Prefix sums represent:
(0,0) → 1
(0,1) → 3
(1,0) → 4
(1,1) → 10

We count how many are ≤ k.
*/

class Solution {
public:

    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> rowpref(row, vector<int>(col, 0));
        vector<vector<int>> all(row, vector<int>(col, 0));

        // Row prefix sums
        for (int i = 0; i < row; i++) {

            int sum = 0;

            for (int j = 0; j < col; j++) {

                sum += grid[i][j];

                rowpref[i][j] = sum;
            }
        }

        // Convert to full 2D prefix sum
        for (int j = 0; j < col; j++) {

            int sum = 0;

            for (int i = 0; i < row; i++) {

                sum += rowpref[i][j];

                all[i][j] = sum;
            }
        }

        int cnt = 0;

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {

                if (all[i][j] <= k)
                    cnt++;
                else
                    break;
            }
        }

        return cnt;
    }
};
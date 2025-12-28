// Problem: Count Negative Numbers in a Sorted Matrix
// Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Approach: Top-right corner traversal
// Time Complexity: O(m + n)
// Space Complexity: O(1)

/*
Explanation:
The matrix is sorted in non-increasing order both row-wise and column-wise.

Approach:
1. Start from the top-right corner of the matrix.
2. If the current element is non-negative:
   - Move down to the next row.
3. If the current element is negative:
   - All elements below it in the same column are also negative.
   - Add (m - row) to the count.
   - Move left to the previous column.
4. Continue until all rows or columns are processed.

This allows counting all negative numbers efficiently
without checking every element.
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int row = 0;
        int col = n - 1;
        int cnt = 0;

        while (row < m && col >= 0) {
            if (grid[row][col] >= 0) {
                row++;
            } else {
                cnt += (m - row);
                col--;
            }
        }

        return cnt;
    }
};

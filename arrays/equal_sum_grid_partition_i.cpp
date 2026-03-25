// Problem: Equal Sum Grid Partition I
// Link: https://leetcode.com/problems/equal-sum-grid-partition-i/
// Approach: Prefix Sum (Row-wise and Column-wise)
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

/*
Explanation:

We are given a grid.

Goal:
Check if we can partition the grid into two parts such that
the sum of both parts is equal.

We can partition:
1. Horizontally → split rows
2. Vertically → split columns

------------------------------------------------

Approach:

1. Compute row-wise prefix sums:
   row[i][j] → sum of row i from column 0 to j

2. Build:
   rowpref[i] → sum of all elements from row 0 to i
   rowsuff[i] → sum of all elements from row i to last row

3. Check horizontal splits:
   if rowpref[i] == rowsuff[i+1] → valid partition

------------------------------------------------

4. Compute column-wise prefix sums:
   col[i][j] → sum of column j from row 0 to i

5. Build:
   colpref[j] → sum of all elements from column 0 to j
   colsuff[j] → sum of all elements from column j to last column

6. Check vertical splits:
   if colpref[j] == colsuff[j+1] → valid partition

------------------------------------------------

If any valid split exists → return true
Else → return false
*/

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<long long>> row(r, vector<long long>(c, 0));

        // Row prefix sums
        for (int i = 0; i < r; i++) {

            long long sum = 0;

            for (int j = 0; j < c; j++) {

                sum += grid[i][j];
                row[i][j] = sum;
            }
        }

        vector<long long> rowpref(r, 0);
        long long sum = 0;

        for (int i = 0; i < r; i++) {
            sum += row[i][c - 1];
            rowpref[i] = sum;
        }

        vector<long long> rowsuff(r, 0);
        sum = 0;

        for (int i = r - 1; i >= 0; i--) {
            sum += row[i][c - 1];
            rowsuff[i] = sum;
        }

        // Column prefix sums
        vector<vector<long long>> col(r, vector<long long>(c, 0));

        for (int j = 0; j < c; j++) {

            long long sum = 0;

            for (int i = 0; i < r; i++) {

                sum += grid[i][j];
                col[i][j] = sum;
            }
        }

        vector<long long> colpref(c, 0);
        sum = 0;

        for (int j = 0; j < c; j++) {
            sum += col[r - 1][j];
            colpref[j] = sum;
        }

        vector<long long> colsuff(c, 0);
        sum = 0;

        for (int j = c - 1; j >= 0; j--) {
            sum += col[r - 1][j];
            colsuff[j] = sum;
        }

        // Check horizontal partition
        for (int i = 0; i < r - 1; i++) {
            if (rowpref[i] == rowsuff[i + 1])
                return true;
        }

        // Check vertical partition
        for (int j = 0; j < c - 1; j++) {
            if (colpref[j] == colsuff[j + 1])
                return true;
        }

        return false;
    }
};
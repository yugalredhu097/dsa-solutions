// Problem: Count Submatrices With Equal Frequency of X and Y
// Link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/
// Approach: 2D Prefix Sum (Separate counts for X and Y)
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

/*
Explanation:

We are given a grid containing characters:
'X', 'Y', or others.

Goal:
Count the number of submatrices starting from (0,0)
such that:
1. Number of 'X' == number of 'Y'
2. At least one 'X' is present

------------------------------------------------

Key Idea:

We use 2D prefix sums separately for:
- count of 'X'
- count of 'Y'

Steps:

1. Build row-wise prefix sums:
   xrow[i][j] → number of 'X' in row i till column j
   yrow[i][j] → number of 'Y' in row i till column j

2. Convert to full 2D prefix sums:
   xall[i][j] → total 'X' in rectangle (0,0) to (i,j)
   yall[i][j] → total 'Y' in rectangle (0,0) to (i,j)

3. For each cell (i,j):
   - Check if:
        xall[i][j] >= 1  (at least one 'X')
        xall[i][j] == yall[i][j]
   - If yes, increment count

------------------------------------------------

This efficiently counts all valid submatrices
in O(m * n) time.
*/

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> xrow(row, vector<int>(col, 0));
        vector<vector<int>> yrow(row, vector<int>(col, 0));

        // Row-wise prefix sums
        for (int i = 0; i < row; i++) {

            int sum1 = 0, sum2 = 0;

            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 'X') sum1++;
                if (grid[i][j] == 'Y') sum2++;

                xrow[i][j] = sum1;
                yrow[i][j] = sum2;
            }
        }

        vector<vector<int>> xall(row, vector<int>(col, 0));
        vector<vector<int>> yall(row, vector<int>(col, 0));

        // Build 2D prefix sums
        for (int j = 0; j < col; j++) {

            int sum1 = 0, sum2 = 0;

            for (int i = 0; i < row; i++) {

                sum1 += xrow[i][j];
                xall[i][j] = sum1;

                sum2 += yrow[i][j];
                yall[i][j] = sum2;
            }
        }

        int cnt = 0;

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {

                if (xall[i][j] >= 1 && xall[i][j] == yall[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};
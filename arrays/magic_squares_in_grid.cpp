// Problem: Magic Squares In Grid
// Link: https://leetcode.com/problems/magic-squares-in-grid/
// Approach: Brute force check for each 3x3 subgrid
// Time Complexity: O(m * n)
// Space Complexity: O(1)

/*
Explanation:
A 3x3 grid is a magic square if:
1. All numbers are distinct and in the range [1, 9].
2. The sum of each row, each column, and both diagonals is the same.

Approach:
1. Traverse all possible 3x3 subgrids.
2. For each subgrid:
   - Check all numbers are between 1 and 9 and distinct.
   - Compute the sum of the first row.
   - Verify all rows, columns, and diagonals match this sum.
3. Count all valid magic squares.

Since the subgrid size is fixed (3x3), each check is constant time.
*/

class Solution {
public:

    // Check if all elements are distinct
    bool alldistinct(vector<int> temp) {
        sort(temp.begin(), temp.end());
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] == temp[i - 1])
                return false;
        }
        return true;
    }

    // Check if a 3x3 subgrid is a magic square
    bool ismagicsquare(vector<vector<int>>& grid,
                       int lcol, int rcol,
                       int urow, int drow) {

        vector<int> temp;

        // Check range and collect elements
        for (int i = urow; i <= drow; i++) {
            for (int j = lcol; j <= rcol; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9)
                    return false;
                temp.push_back(num);
            }
        }

        if (!alldistinct(temp))
            return false;

        // Row sum
        int sum = 0;
        for (int j = lcol; j <= rcol; j++) {
            sum += grid[urow][j];
        }

        // Check rows
        for (int i = urow; i <= drow; i++) {
            int rowSum = 0;
            for (int j = lcol; j <= rcol; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum != sum)
                return false;
        }

        // Check columns
        for (int j = lcol; j <= rcol; j++) {
            int colSum = 0;
            for (int i = urow; i <= drow; i++) {
                colSum += grid[i][j];
            }
            if (colSum != sum)
                return false;
        }

        // Check main diagonal
        int diagSum = 0;
        for (int i = 0; i < 3; i++) {
            diagSum += grid[urow + i][lcol + i];
        }
        if (diagSum != sum)
            return false;

        // Check anti-diagonal
        diagSum = 0;
        for (int i = 0; i < 3; i++) {
            diagSum += grid[urow + i][rcol - i];
        }
        if (diagSum != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if (m < 3 || n < 3)
            return 0;

        int count = 0;

        // Traverse all 3x3 subgrids
        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                if (ismagicsquare(grid, j, j + 2, i, i + 2))
                    count++;
            }
        }

        return count;
    }
};

// Problem: Largest Magic Square (LeetCode 1895)
// Link: https://leetcode.com/problems/largest-magic-square/
// Approach: Brute force check for every possible k x k submatrix
// Time Complexity: O(n * m * min(n, m)^2)
// Space Complexity: O(1)

/*
Explanation:
A magic square is a k x k submatrix where:
- All rows have the same sum
- All columns have the same sum
- Both diagonals have the same sum

Approach:
1. For every cell (i, j), treat it as the top-left corner.
2. Try all possible square sizes k ≥ 2 that fit inside the grid.
3. For each k x k square:
   - Compute the sum of the first row (target).
   - Verify all rows match the target sum.
   - Verify all columns match the target sum.
   - Verify both diagonals match the target sum.
4. Track the maximum k found.
5. A single cell is always a valid magic square (k = 1).
*/

class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c, int k) {
        int target = 0;

        // First row sum
        for (int j = c; j < c + k; j++)
            target += grid[r][j];

        // Check all rows
        for (int i = r; i < r + k; i++) {
            int sum = 0;
            for (int j = c; j < c + k; j++)
                sum += grid[i][j];
            if (sum != target) return false;
        }

        // Check all columns
        for (int j = c; j < c + k; j++) {
            int sum = 0;
            for (int i = r; i < r + k; i++)
                sum += grid[i][j];
            if (sum != target) return false;
        }

        // Main diagonal
        int diag1 = 0;
        for (int i = 0; i < k; i++)
            diag1 += grid[r + i][c + i];

        // Anti-diagonal
        int diag2 = 0;
        for (int i = 0; i < k; i++)
            diag2 += grid[r + i][c + k - 1 - i];

        return diag1 == target && diag2 == target;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 1; // Single cell is always a magic square

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 2; i + k <= n && j + k <= m; k++) {
                    if (isMagic(grid, i, j, k)) {
                        ans = max(ans, k);
                    }
                }
            }
        }
        return ans;
    }
};

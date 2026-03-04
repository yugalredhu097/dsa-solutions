// Problem: Special Positions in a Binary Matrix
// Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
// Approach: Brute Force Row and Column Check
// Time Complexity: O(m * n * (m + n))
// Space Complexity: O(1)

/*
Explanation:
A position (i, j) is called special if:
- mat[i][j] == 1
- All other elements in row i are 0
- All other elements in column j are 0

Approach:
1. Traverse every cell of the matrix.
2. If the cell contains 1, check:
   - All elements in the same column except the current row.
   - All elements in the same row except the current column.
3. If both checks pass, increment the count.
*/

class Solution {
public:
    bool isSpecial(int row, int col, vector<vector<int>> &mat) {

        // Check column
        for (int i = 0; i < mat.size(); i++) {
            if (i == row) continue;
            if (mat[i][col] == 1) return false;
        }

        // Check row
        for (int j = 0; j < mat[0].size(); j++) {
            if (j == col) continue;
            if (mat[row][j] == 1) return false;
        }

        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1 && isSpecial(i, j, mat)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
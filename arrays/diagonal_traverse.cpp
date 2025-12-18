// Problem: Diagonal Traverse
// Link: https://leetcode.com/problems/diagonal-traverse/
// Approach: Simulation of diagonal movement
// Time Complexity: O(m * n)
// Space Complexity: O(1) (excluding output array)

/*
Explanation:
We traverse the matrix in a zig-zag diagonal order.

Rules:
1. Move upward-right (↗) until hitting a boundary.
2. Adjust the position:
   - If at last column → move down
   - Else → move right
3. Move downward-left (↙) until hitting a boundary.
4. Adjust the position:
   - If at last row → move right
   - Else → move down
5. Repeat until all elements are collected.

This approach simulates the exact movement of the diagonal traversal.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        int total = m * n;

        vector<int> ans;
        ans.reserve(total);

        int row = 0, col = 0;
        int cnt = 0;

        while (cnt < total) {

            // Move upward-right
            while (row >= 0 && col < n) {
                ans.push_back(mat[row][col]);
                cnt++;
                row--;
                col++;
            }

            row++;
            col--;

            if (col == n - 1)
                row++;
            else
                col++;

            // Move downward-left
            while (row < m && col >= 0) {
                ans.push_back(mat[row][col]);
                cnt++;
                row++;
                col--;
            }

            row--;
            col++;

            if (row == m - 1)
                col++;
            else
                row++;
        }

        return ans;
    }
};

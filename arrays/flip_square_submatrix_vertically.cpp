// Problem: Flip Square Submatrix Vertically
// Link: https://leetcode.com/problems/flip-square-submatrix-vertically/
// Approach: Simulation (Reverse Rows in k×k Submatrix)
// Time Complexity: O(k^2)
// Space Complexity: O(k^2)

/*
Explanation:

We are given:
- A grid
- Top-left coordinates (x, y)
- Size k

Goal:
Flip the k × k submatrix vertically.

------------------------------------------------

What does "flip vertically" mean?

We reverse the order of rows inside the selected
k × k submatrix.

Example:

Before:
1 2
3 4

After vertical flip:
3 4
1 2

------------------------------------------------

Approach:

1. Extract the k × k submatrix from bottom to top.
2. Store it in a temporary matrix.
3. Copy it back into the original grid.

------------------------------------------------

This effectively reverses the rows within the submatrix.
*/

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        vector<vector<int>> temp;

        // Extract submatrix in reversed row order
        for (int i = x + k - 1; i >= x; i--) {

            vector<int> t;

            for (int j = y; j <= y + k - 1; j++) {
                t.push_back(grid[i][j]);
            }

            temp.push_back(t);
        }

        // Put back into original grid
        for (int i = x; i <= x + k - 1; i++) {

            for (int j = y; j <= y + k - 1; j++) {
                grid[i][j] = temp[i - x][j - y];
            }
        }

        return grid;
    }
};
// Problem: Get Biggest Three Rhombus Sums in a Grid
// Link: https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
// Approach: Grid Traversal + Simulation of Rhombus Borders
// Time Complexity: O(n * m * min(n,m))
// Space Complexity: O(n)

/*
Explanation:

We are given a 2D grid. A rhombus in the grid is formed by
connecting four points:

Top
Left
Right
Bottom

The rhombus border consists of four diagonal edges.

Goal:
Find the three largest distinct rhombus border sums.

------------------------------------------------

Approach:

1. Every single cell itself forms a rhombus of size 0.
   So we first add all grid[i][j] values.

2. For larger rhombuses:
   The side length must increase by 1 on both diagonals,
   meaning the bounding box increases by 2.

3. For every possible rhombus:
   - Calculate the border sum by walking along
     the four diagonals:
        top → left
        top → right
        left → bottom
        right → bottom

4. Store all rhombus sums in a vector.

5. Sort the vector in descending order.

6. Extract the top three **distinct** values.

------------------------------------------------

Example:

Grid:
3 4 5
3 3 4
20 30 200

Possible rhombus sums are calculated from borders,
and we return the three largest unique sums.
*/

class Solution {
public:

    int rhomsum(vector<vector<int>> &g, int strow, int endrow, int stcol, int endcol) {

        int upmidcol = (endcol + stcol) / 2;
        int upmidrow = strow;

        int lowmidcol = (endcol + stcol) / 2;
        int lowmidrow = endrow;

        int lmidcol = stcol;
        int lmidrow = (endrow + strow) / 2;

        int rmidcol = endcol;
        int rmidrow = (endrow + strow) / 2;

        int sum = 0;

        // top → left
        for (int i = upmidrow, j = upmidcol; i <= lmidrow && j >= lmidcol; i++, j--) {
            sum += g[i][j];
        }

        // top → right
        for (int i = upmidrow + 1, j = upmidcol + 1; i <= rmidrow && j <= rmidcol; i++, j++) {
            sum += g[i][j];
        }

        // left → bottom
        for (int i = lmidrow + 1, j = lmidcol + 1; i <= lowmidrow && j <= lowmidcol; i++, j++) {
            sum += g[i][j];
        }

        // right → bottom
        for (int i = rmidrow + 1, j = rmidcol - 1; i < lowmidrow && j > lowmidcol; i++, j--) {
            sum += g[i][j];
        }

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        vector<int> temp;

        int row = grid.size();
        int col = grid[0].size();

        // Single cell rhombus
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                temp.push_back(grid[i][j]);
            }
        }

        // Larger rhombuses
        for (int i = 2; i < row && i < col; i += 2) {

            for (int j = 0; j < row - i; j++) {

                for (int k = 0; k < col - i; k++) {

                    temp.push_back(rhomsum(grid, j, j + i, k, k + i));
                }
            }
        }

        vector<int> ans;

        sort(temp.rbegin(), temp.rend());

        for (int n : temp) {

            if (!ans.empty() && ans.back() == n)
                continue;

            ans.push_back(n);

            if (ans.size() == 3)
                break;
        }

        return ans;
    }
};
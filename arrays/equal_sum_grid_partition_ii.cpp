// Problem: Equal Sum Grid Partition II
// Link: https://leetcode.com/problems/equal-sum-grid-partition-ii/
// Approach: Prefix Sum + Hashing + Grid Rotation
// Time Complexity: O(4 * m * n)
// Space Complexity: O(m * n)

/*
Explanation:

We are given a grid.

Goal:
Check if we can partition the grid into two parts such that:
- The sums are equal
- We may remove at most one element

------------------------------------------------

Key Idea:

1. Compute total sum of the grid.

2. Try partitioning horizontally:
   - Maintain running sum of top part
   - Compute:
        tag = 2 * sum - total
   - If tag exists in the partition → valid split

3. Use a hash set to track elements in the current partition.

4. Handle edge cases:
   - Single column
   - First row

5. Rotate the grid 4 times to simulate:
   - Horizontal splits
   - Vertical splits

------------------------------------------------

Rotation:

We rotate the grid 90 degrees clockwise:
tmp[j][m - 1 - i] = grid[i][j]

This avoids writing separate logic for vertical partitions.

------------------------------------------------

Condition:

If we can remove one element such that both partitions
have equal sum → return true.

Otherwise → false.
*/

class Solution {
public:

    // Rotate grid 90 degrees clockwise
    vector<vector<int>> rotation(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> tmp(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }

        return tmp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {

        long long total = 0;

        int m = grid.size();
        int n = grid[0].size();

        // Compute total sum
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        unordered_set<long long> exist;

        for (int k = 0; k < 4; k++) {

            exist.clear();
            exist.insert(0);

            long long sum = 0;

            m = grid.size();
            n = grid[0].size();

            if (m < 2) {
                grid = rotation(grid);
                continue;
            }

            // Special case: single column
            if (n == 1) {

                for (int i = 0; i < m - 1; i++) {

                    sum += grid[i][0];

                    long long tag = sum * 2 - total;

                    if (tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                        return true;
                    }
                }

                grid = rotation(grid);
                continue;
            }

            // General case
            for (int i = 0; i < m - 1; i++) {

                for (int j = 0; j < n; j++) {
                    exist.insert(grid[i][j]);
                    sum += grid[i][j];
                }

                long long tag = sum * 2 - total;

                if (i == 0) {

                    if (tag == 0 || tag == grid[0][0] || tag == grid[0][n - 1]) {
                        return true;
                    }

                    continue;
                }

                if (exist.contains(tag)) {
                    return true;
                }
            }

            // Rotate grid to check other orientations
            grid = rotation(grid);
        }

        return false;
    }
};
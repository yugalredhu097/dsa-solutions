// Problem: Minimum Operations to Make a Uni-Value Grid
// Link: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
// Approach: Flatten Grid + Median + Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:

We are given a grid and integer x.

In one operation:
Increase or decrease any element by x.

Goal:
Make all grid values equal using minimum operations.

------------------------------------------------

Key Observation:

1. All values must have same remainder modulo x,
   otherwise impossible.

2. To minimize total moves:
   choose the median value.

Why median?

Median minimizes sum of absolute differences.

------------------------------------------------

Steps:

1. Flatten grid into array
2. Sort array
3. Choose median
4. Check divisibility by x
5. Sum required operations

------------------------------------------------

If any difference is not divisible by x:
return -1
*/

class Solution {
public:

    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> arr;

        int r = grid.size();
        int c = grid[0].size();

        // Flatten grid
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int mid = arr[n / 2];

        int ops = 0;

        for (int val : arr) {

            int diff = abs(val - mid);

            if (diff % x != 0)
                return -1;

            ops += diff / x;
        }

        return ops;
    }
};
// Problem: Kth Smallest Element in a Sorted Matrix
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Approach: Binary Search on Answer + count elements <= mid
// Time Complexity: O(n log (max - min))
// Space Complexity: O(1)

/*
Explanation:
The matrix is sorted in ascending order both row-wise and column-wise.

We apply binary search on the answer range:
- Lowest possible value = matrix[0][0]
- Highest possible value = matrix[n-1][n-1]

For a guessed value `mid`:
1. Count how many elements in the matrix are <= mid.
   This is done efficiently by scanning from the top-right corner.
2. If count == k → mid (or closest smaller value) is the answer.
3. If count < k → move search to right (increase low).
4. If count > k → move search to left (decrease high).

This avoids flattening the matrix and keeps space usage constant.
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            ans = low;

            // Count elements <= mid
            for (int i = 0, j = n - 1; i < n; i++) {
                while (j >= 0 && matrix[i][j] > mid)
                    j--;

                if (j >= 0) {
                    cnt += (j + 1);
                    ans = max(ans, matrix[i][j]);
                } else {
                    break;
                }
            }

            if (cnt == k) {
                return ans;
            } else if (cnt < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};

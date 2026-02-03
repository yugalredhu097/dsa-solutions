// Problem: Trionic Array
// Link: https://leetcode.com/problems/trionic-array/
// Approach: One-pass validation with state transitions
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
An array is called trionic if it has three strictly monotonic parts:
1. Strictly increasing
2. Strictly decreasing
3. Strictly increasing

Additionally:
- Each part must contain at least one element.
- No two adjacent elements can be equal.

Approach:
1. Traverse from the start to find the first decreasing point (p).
2. Traverse from p to find the next increasing point (q).
3. From q onward, ensure the array is strictly increasing.
4. If all conditions are satisfied, return true.

This single-pass style check ensures efficiency and correctness.
*/

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return false;

        int p = -1, q = -1;

        // Find first decreasing point
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) return false;
            if (nums[i] > nums[i + 1]) {
                p = i;
                break;
            }
        }

        if (p <= 0 || p >= n - 2) return false;

        // Find next increasing point
        for (int i = p; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) return false;
            if (nums[i] < nums[i + 1]) {
                q = i;
                break;
            }
        }

        if (q == -1) return false;

        // Validate final increasing sequence
        for (int i = q; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) return false;
        }

        return true;
    }
};

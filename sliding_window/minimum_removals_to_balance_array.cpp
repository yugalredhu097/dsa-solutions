// Problem: Minimum Removals to Balance Array
// Link: https://www.geeksforgeeks.org/problems/minimum-removals-to-balance-array/1
// Approach: Sorting + Two Pointers (Sliding Window)
// Time Complexity: O(n log n)
// Space Complexity: O(1)

/*
Explanation:
An array is considered balanced if:
maxElement <= k * minElement

We need to remove the minimum number of elements so that
the remaining array satisfies this condition.

Approach:
1. Sort the array.
2. Use two pointers `l` and `r` to maintain a valid window.
3. If nums[l] * k < nums[r], move `l` forward to restore balance.
4. For each valid window, calculate the number of elements removed:
   removals = n - (r - l + 1)
5. Track the minimum removals across all valid windows.

This efficiently finds the largest valid subarray.
*/

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int minRemovals = n;
        int l = 0, r = 0;

        while (r < n && l < n) {
            while (l < n && r < n && 1LL * nums[l] * k < nums[r]) {
                l++;
            }
            minRemovals = min(minRemovals, n - (r - l + 1));
            r++;
        }

        return minRemovals;
    }
};

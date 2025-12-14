// Problem: Absolute Difference Between Maximum and Minimum K Elements
// Link: https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/
// Approach: Sorting + prefix sums
// Time Complexity: O(n log n)
// Space Complexity: O(1) (ignoring input array)

/*
Explanation:
We are given an array `nums` and an integer `k`.

Goal:
- Select k smallest elements → compute their sum
- Select k largest elements  → compute their sum
- Return the absolute difference between these two sums

Steps:
1. Sort the array.
2. Sum the first k elements (minimum k elements).
3. Sum the last k elements (maximum k elements).
4. Return |sum_max - sum_min|.

Sorting helps us easily access smallest and largest k elements.
*/

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {

        // Sort the array
        sort(nums.begin(), nums.end());

        long long minSum = 0;
        long long maxSum = 0;
        int n = nums.size();

        // Sum of k smallest elements
        for (int i = 0; i < k; i++) {
            minSum += nums[i];
        }

        // Sum of k largest elements
        for (int i = n - k; i < n; i++) {
            maxSum += nums[i];
        }

        // Absolute difference
        return abs(minSum - maxSum);
    }
};

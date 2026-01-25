// Problem: Minimum Difference Between Highest and Lowest of K Scores (LeetCode 1984)
// Link: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// Approach: Sorting + Sliding Window
// Time Complexity: O(n log n)
// Space Complexity: O(1)

/*
Explanation:
We want to choose k elements such that the difference between the
maximum and minimum among them is minimized.

Steps:
1. Sort the array.
2. Use a sliding window of size k.
3. For each window, compute:
      nums[i + k - 1] - nums[i]
4. Track the minimum difference.
*/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int mini = INT_MAX;
        for (int i = 0; i <= nums.size() - k; i++) {
            mini = min(mini, nums[i + k - 1] - nums[i]);
        }
        return mini;
    }
};

// Problem: Final Element
// LeetCode ID: 3828
// Link: https://leetcode.com/problems/final-element/
// Approach: Direct Comparison
// Time Complexity: O(1)
// Space Complexity: O(1)

/*
Explanation:
Given an integer array `nums`, the task is to return the final element
based on the comparison of the first and last elements.

Approach:
1. Compare the first element `nums[0]` and the last element `nums[n-1]`.
2. Return the maximum of the two.

This solution works in constant time and requires no extra space.
*/

class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums[0], nums[nums.size() - 1]);
    }
};

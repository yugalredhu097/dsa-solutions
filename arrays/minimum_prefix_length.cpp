// Problem: Minimum Prefix Length (LeetCode 3818)
// Link: https://leetcode.com/problems/minimum-prefix-length/
// Approach: Single pass from right
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We want the smallest prefix such that removing it makes the remaining
array strictly increasing.

Approach:
- Traverse the array from right to left.
- Find the first position where nums[i-1] >= nums[i].
- The answer is index i.
- If no such position exists, the array is already strictly increasing,
  so return 0.
*/

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int k = 0;
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i - 1] >= nums[i]) {
                k = i;
                break;
            }
        }
        return k;
    }
};

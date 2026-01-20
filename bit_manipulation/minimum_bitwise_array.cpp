// Problem: Minimum Bitwise Array (LeetCode 3314)
// Link: https://leetcode.com/problems/minimum-bitwise-array/
// Approach: Brute force using bitwise OR
// Time Complexity: O(n * max(nums[i]))
// Space Complexity: O(n)

/*
Explanation:
For each number nums[i], we want to find the smallest integer j such that:
    j | (j + 1) == nums[i]

Approach:
- Initialize answer array with -1.
- For each nums[i], try all values of j from 0 to nums[i] - 1.
- Compute (j | (j + 1)).
- If it equals nums[i], store j and break.
- If no such j exists, answer remains -1.
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i]; j++) {
                int val = j | (j + 1);
                if (val == nums[i]) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};

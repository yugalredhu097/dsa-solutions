// Problem: Jump Game
// Link: https://leetcode.com/problems/jump-game/
// Approach: Greedy (track maximum reachable index)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
Each element in the array represents the maximum jump length
from that position.

Approach:
1. Maintain a variable `maxreach` that stores the farthest index
   reachable so far.
2. Traverse the array:
   - If current index `i` is greater than `maxreach`, we cannot
     reach this position → return false.
   - Otherwise, update `maxreach = max(maxreach, i + nums[i])`.
3. If we successfully traverse the array, return true.

This greedy strategy ensures optimal performance.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxreach = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxreach)
                return false;

            maxreach = max(maxreach, i + nums[i]);
        }

        return true;
    }
};

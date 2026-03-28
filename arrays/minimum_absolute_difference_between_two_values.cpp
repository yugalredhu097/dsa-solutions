// Problem: Minimum Absolute Difference Between Two Values
// Link: https://leetcode.com/problems/minimum-absolute-difference-between-two-values/
// Approach: Brute Force (Check distances between 1 and 2)
// Time Complexity: O(n^2)
// Space Complexity: O(1)

/*
Explanation:

We are given an array nums.

Goal:
Find the minimum absolute difference between indices i and j
such that:
nums[i] = 1 and nums[j] = 2

------------------------------------------------

Approach:

1. Traverse the array.
2. For every occurrence of 1:
   - Search to the right for 2
   - Search to the left for 2
3. Track the minimum distance.

4. If no valid pair exists → return -1.

------------------------------------------------

This is a brute force approach.

------------------------------------------------

Note:

An optimized approach exists:
→ Traverse once and keep track of last seen positions
→ Time Complexity can be reduced to O(n)
*/

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {

        int mini = INT_MAX;

        // Check right side
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 1) {

                for (int j = i + 1; j < nums.size(); j++) {

                    if (nums[j] == 2)
                        mini = min(mini, abs(j - i));
                }
            }
        }

        // Check left side
        for (int i = nums.size() - 1; i >= 0; i--) {

            if (nums[i] == 1) {

                for (int j = i - 1; j >= 0; j--) {

                    if (nums[j] == 2)
                        mini = min(mini, abs(j - i));
                }
            }
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};
// Problem: Binary Subarrays With Sum
// Link: https://leetcode.com/problems/binary-subarrays-with-sum/
// Approach: Sliding Window + Inclusion-Exclusion
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We are given a binary array and a target sum `goal`.
We need to count the number of subarrays whose sum equals `goal`.

Key Idea:
Number of subarrays with sum == goal =
(number of subarrays with sum <= goal)
- (number of subarrays with sum <= goal - 1)

This works because the array contains only 0s and 1s.

Approach:
1. Create a helper function that counts subarrays with sum <= X
   using a sliding window.
2. Call it twice:
   - once for `goal`
   - once for `goal - 1`
3. Subtract the two results to get exact sum == goal.
*/

class Solution {
public:

    // Count subarrays with sum <= goal
    int subarrlessthanequalto(vector<int>& nums, int goal) {

        if (goal < 0)
            return 0;

        int l = 0, sum = 0, cnt = 0;

        for (int r = 0; r < nums.size(); r++) {

            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            cnt += (r - l + 1);
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int atMostGoal = subarrlessthanequalto(nums, goal);
        int atMostGoalMinusOne = subarrlessthanequalto(nums, goal - 1);

        return atMostGoal - atMostGoalMinusOne;
    }
};

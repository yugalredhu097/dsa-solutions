// Problem: Minimum Cost
// LeetCode ID: 3010
// Link: https://leetcode.com/problems/minimum-cost/
// Approach: Greedy (select two minimum elements after index 0)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
Given an integer array `nums`, the minimum cost is calculated by:
- Taking the first element `nums[0]`
- Adding the two smallest elements from the remaining array

Approach:
1. Initialize the total cost with the first element.
2. Find the smallest element (firstMin) from index 1 to n-1.
3. Find the second smallest element (secondMin) from index 1 to n-1,
   excluding the index of firstMin.
4. Add all three values to get the minimum possible cost.

This greedy strategy guarantees the optimal result.
*/

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost = nums[0];

        int firstMin = INT_MAX, secondMin = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < firstMin) {
                secondMin = firstMin;
                firstMin = nums[i];
            } else if (nums[i] < secondMin) {
                secondMin = nums[i];
            }
        }

        return cost + firstMin + secondMin;
    }
};

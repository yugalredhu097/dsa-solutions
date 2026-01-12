// Problem: Number of Centered Subarrays
// LeetCode: 3804
// Link: https://leetcode.com/problems/number-of-centered-subarrays/
// Approach: Brute Force (Check all subarrays)
// Time Complexity: O(n^3)
// Space Complexity: O(1)

/*
Explanation:
A subarray is called "centered" if:
- The sum of elements in the subarray exists as an element
  within the same subarray.

Approach:
1. Generate all possible subarrays using two loops.
2. For each subarray [i..j]:
   - Compute the sum of elements.
   - Check if the sum exists within that subarray.
3. If yes, increment the count.

This brute-force approach is acceptable for small constraints.
*/

class Solution {
public:

    // Compute sum of subarray from index a to b
    int summation(vector<int>& nums, int a, int b) {
        int sum = 0;
        for (int i = a; i <= b; i++) {
            sum += nums[i];
        }
        return sum;
    }

    // Check if value k is present in subarray [a..b]
    bool ispresent(vector<int>& nums, int k, int a, int b) {
        for (int i = a; i <= b; i++) {
            if (nums[i] == k)
                return true;
        }
        return false;
    }

    int centeredSubarrays(vector<int>& nums) {

        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {

                int sum = summation(nums, i, j);

                if (ispresent(nums, sum, i, j))
                    cnt++;
            }
        }

        return cnt;
    }
};

// Problem: Longest Balanced Subarray I
// Link: https://leetcode.com/problems/longest-balanced-subarray-i/
// Approach: Brute-force with sets to track distinct even and odd elements
// Time Complexity: O(n^2)
// Space Complexity: O(n)

/*
Explanation:
A subarray is considered balanced if the number of distinct
even elements equals the number of distinct odd elements.

Approach:
1. For each starting index i:
   - Maintain two sets:
     • one for distinct even elements
     • one for distinct odd elements
2. Expand the subarray to the right.
3. At each step, check if the sizes of both sets are equal.
4. Update the maximum length if balanced.

This brute-force approach checks all possible subarrays.
*/

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> even;
            unordered_set<int> odd;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    even.insert(nums[j]);
                else
                    odd.insert(nums[j]);

                if (even.size() == odd.size())
                    maxi = max(maxi, j - i + 1);
            }
        }

        return maxi;
    }
};

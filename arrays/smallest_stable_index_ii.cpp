// Problem: Smallest Stable Index II
// Link: https://leetcode.com/problems/smallest-stable-index-ii/
// Approach: Prefix Maximum + Suffix Minimum
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given:
- nums array
- integer k

Goal:
Find the first index i such that:

max(nums[0...i]) - min(nums[i...n-1]) <= k

Return the first such index,
otherwise return -1.

------------------------------------------------

Key Idea:

For every index i we need:

1. Prefix maximum up to i
2. Suffix minimum from i to end

Then check:

prefixMax[i] - suffixMin[i] <= k

------------------------------------------------

Steps:

1. Build prefix max array
2. Build suffix min array
3. Traverse from left to right
4. Return first valid index

------------------------------------------------

Why preprocessing?

Without it:
Each index would need repeated max/min scans.

With preprocessing:
Each query becomes O(1).
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> maxpref(n);
        vector<int> minsuff(n);

        int maxi = INT_MIN;
        int mini = INT_MAX;

        // Build prefix max and suffix min
        for (int i = 0; i < n; i++) {

            maxi = max(maxi, nums[i]);
            maxpref[i] = maxi;

            mini = min(mini, nums[n - 1 - i]);
            minsuff[n - 1 - i] = mini;
        }

        // Find first valid index
        for (int i = 0; i < n; i++) {

            if (maxpref[i] - minsuff[i] <= k)
                return i;
        }

        return -1;
    }
};
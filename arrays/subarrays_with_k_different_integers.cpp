// Problem: Subarrays with K Different Integers
// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
// Approach: Sliding Window + At Most K Technique
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We need to count the number of subarrays that contain
exactly k distinct integers.

Key Insight:
Number of subarrays with exactly k distinct elements =
    (subarrays with at most k distinct elements)
  - (subarrays with at most k-1 distinct elements)

Approach:
1. Use a helper function that counts subarrays with at most k distinct elements
   using a sliding window and a frequency map.
2. Call this helper for k and k-1.
3. Subtract the results to get the exact count.

This converts an exact-count problem into two easier at-most problems.
*/

class Solution {
public:

    // Count subarrays with at most k distinct integers
    int subarrays(vector<int>& nums, int k) {

        map<int, int> mpp;
        int l = 0, cnt = 0;
        int n = nums.size();

        for (int r = 0; r < n; r++) {

            mpp[nums[r]]++;

            // Shrink window if more than k distinct elements
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }

            // Count valid subarrays ending at r
            cnt += (r - l + 1);
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int atMostK = subarrays(nums, k);
        int atMostKMinusOne = subarrays(nums, k - 1);

        return atMostK - atMostKMinusOne;
    }
};

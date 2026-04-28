// Problem: Max Consecutive Ones III
// Link: https://leetcode.com/problems/max-consecutive-ones-iii/
// Approach: Sliding Window (at most k zeroes)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We are allowed to flip at most k zeroes to ones.
So the problem reduces to finding the longest subarray
that contains at most k zeroes.

Approach:
1. Use a sliding window with two pointers (l and r).
2. Expand the window by moving r.
3. Count how many zeroes are inside the window.
4. If zero count exceeds k, shrink the window from the left.
5. Keep track of the maximum window size where zero count <= k.

This guarantees an optimal O(n) solution.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int maxlen = 0;
        int l = 0, r = 0;
        int zeroCount = 0;
        int n = nums.size();

        while (r < n) {

            if (nums[r] == 0)
                zeroCount++;

            // Shrink window if zeroes exceed k
            while (zeroCount > k) {
                if (nums[l] == 0)
                    zeroCount--;
                l++;
            }

            // Update maximum length
            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};

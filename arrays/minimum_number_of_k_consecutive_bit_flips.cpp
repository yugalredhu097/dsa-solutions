// Problem: Minimum Number of K Consecutive Bit Flips
// Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
// Approach: Sliding Window + Flip Tracking
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given a binary array `nums` and an integer `k`.
In one operation, we can flip `k` consecutive bits
(0 becomes 1 and 1 becomes 0).

Goal:
Return the minimum number of flips required to make
all elements equal to 1. If impossible, return -1.

Key Idea:

Instead of actually flipping k elements every time,
we track flips using a helper array `flip`.

flip[i] = 1 means a flip operation started at index i.

We maintain:
flipCount → number of flips currently affecting this index.

Steps:

1. Traverse the array from left to right.

2. If i >= k, remove the effect of the flip that started
   at index (i - k) because its window no longer affects i.

3. Determine the current value after flips using:
      nums[i] ^ (flipCount % 2)

4. If the result is 0, we must flip starting at index i.

5. If there are not enough elements left to flip (i + k > n),
   return -1.

6. Otherwise:
   - mark flip[i] = 1
   - increase flipCount
   - increase answer.

This avoids repeatedly flipping k elements and
keeps the solution linear.
*/

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        int flipCount = 0;
        int ans = 0;

        vector<int> flip(n, 0);

        for (int i = 0; i < n; i++) {

            // Remove the effect of a flip that is out of range
            if (i >= k)
                flipCount -= flip[i - k];

            // Check current bit after flips
            if ((nums[i] ^ (flipCount % 2)) == 0) {

                // If we cannot flip k elements
                if (i + k > n)
                    return -1;

                // Start a flip at index i
                flip[i] = 1;
                flipCount++;
                ans++;
            }
        }

        return ans;
    }
};
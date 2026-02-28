// Problem: Concatenation of Consecutive Binary Numbers
// Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// Approach: Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We concatenate the binary representations of numbers from 1 to n
and return the decimal value modulo 1e9 + 7.

Approach:
1. Maintain a running result `ans`.
2. For each number i from 1 to n:
   - If i is a power of 2, increase the bit length (`shift`).
   - Left shift `ans` by `shift` bits and add i.
3. Take modulo at each step to avoid overflow.

This works efficiently by tracking binary length dynamically.
*/

class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long ans = 0;
        int shift = 0;

        for (int i = 1; i <= n; ++i) {
            // If i is power of 2, its binary length increases
            if ((i & (i - 1)) == 0) {
                ++shift;
            }
            ans = ((ans << shift) | i) % mod;
        }

        return ans;
    }
};
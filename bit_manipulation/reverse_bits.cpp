// Problem: Reverse Bits
// Link: https://leetcode.com/problems/reverse-bits/
// Approach: Bit Manipulation
// Time Complexity: O(32)
// Space Complexity: O(1)

/*
Explanation:
Given a 32-bit unsigned integer, reverse its bits.

Approach:
1. Extract bits one by one from the given number.
2. Left-shift the result and add the extracted bit.
3. Count how many bits are processed.
4. Left-shift the remaining positions to make the result 32-bit long.

This simulates bit-by-bit reversal.
*/

class Solution {
public:
    int reverseBits(int n) {
        uint32_t ans = 0;
        uint32_t n1 = n;
        int cnt = 0;

        // Reverse bits present in n
        while (n1 > 0) {
            int bit = n1 & 1;
            ans <<= 1;
            ans = ans | bit;
            n1 >>= 1;
            cnt++;
        }

        // Fill remaining bits with zeros
        cnt = 32 - cnt;
        while (cnt > 0) {
            ans <<= 1;
            cnt--;
        }

        return ans;
    }
};

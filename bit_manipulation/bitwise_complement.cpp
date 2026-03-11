// Problem: Complement of Base 10 Integer
// Link: https://leetcode.com/problems/complement-of-base-10-integer/
// Approach: Bit Manipulation (Mask Creation)
// Time Complexity: O(log n)
// Space Complexity: O(1)

/*
Explanation:

The complement of a number means flipping all bits in its binary representation.

Example:
n = 5
Binary representation = 101
Complement            = 010 = 2

Key Idea:

1. Create a mask that has the same number of bits as n but all bits set to 1.
   Example:
   n = 5 (101)
   mask = 111

2. XOR the number with the mask:
   n ^ mask

This flips all bits within the valid range.

Special Case:
If n = 0, the complement is 1.

Steps:

1. Copy n into m.
2. Build a mask by shifting left and adding 1 until m becomes 0.
3. XOR n with the mask to get the complement.
*/

class Solution {
public:
    int bitwiseComplement(int n) {

        int m = n;
        int mask = 0;

        if (n == 0)
            return 1;

        // Create mask with all bits set to 1
        while (m != 0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }

        int ans = n ^ mask;
        return ans;
    }
};
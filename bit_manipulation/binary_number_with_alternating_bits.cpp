// Problem: Binary Number with Alternating Bits
// Link: https://leetcode.com/problems/binary-number-with-alternating-bits/
// Approach: Bit Extraction and Comparison
// Time Complexity: O(log n)
// Space Complexity: O(log n)

/*
Explanation:
A number has alternating bits if no two adjacent bits
in its binary representation are the same.

Approach:
1. Extract all bits of the number from LSB to MSB.
2. Store bits in a vector.
3. Compare adjacent bits.
4. If any two adjacent bits are equal, return false.
5. Otherwise, return true.

This straightforward method checks the condition clearly.
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> bits;

        while (n > 0) {
            int bit = n & 1;
            bits.push_back(bit);
            n >>= 1;
        }

        for (int i = 1; i < bits.size(); i++) {
            if (bits[i - 1] == bits[i]) return false;
        }

        return true;
    }
};

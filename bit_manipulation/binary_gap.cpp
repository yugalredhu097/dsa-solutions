// Problem: Binary Gap
// Link: https://leetcode.com/problems/binary-gap/
// Approach: Bit Extraction + Distance Calculation
// Time Complexity: O(log n)
// Space Complexity: O(log n)

/*
Explanation:
The binary gap of a positive integer is the maximum distance
between two consecutive 1s in its binary representation.

Approach:
1. Extract all bits of the number and store them in a vector.
2. Traverse the bits to find distances between consecutive 1s.
3. Track the maximum distance found.

This method clearly identifies gaps between set bits.
*/

class Solution {
public:
    int binaryGap(int n) {
        vector<int> bits;

        // Extract bits
        while (n > 0) {
            bits.push_back(n & 1);
            n >>= 1;
        }

        int maxD = 0;
        int k = bits.size();
        int i = 0;

        // Find maximum distance between consecutive 1s
        while (i < k) {
            while (i < k && bits[i] == 0) i++;

            int j = i + 1;
            while (j < k && bits[j] == 0) j++;

            if (j < k)
                maxD = max(maxD, j - i);

            i = j;
        }

        return maxD;
    }
};
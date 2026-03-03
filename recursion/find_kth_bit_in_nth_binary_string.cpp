// Problem: Find K-th Bit in N-th Binary String
// Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
// Approach: Recursion + String Construction
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)

/*
Explanation:
The nth binary string is defined recursively:
S1 = "0"
Sn = S(n-1) + "1" + reverse(invert(S(n-1)))

Where:
- invert flips 0 ↔ 1
- reverse reverses the string

Approach:
1. Recursively construct the nth binary string.
2. Use a helper function to invert and reverse a string.
3. Return the (k-1)th character from the final string.

Note:
This solution is simple and clear but exponential in size.
Optimized solutions exist using recursion without building full string.
*/

class Solution {
public:
    string invertreverse(string s) {
        for (char &c : s) {
            c = (c == '1') ? '0' : '1';
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string NthBinaryString(int n) {
        if (n == 1) return "0";

        string prev = NthBinaryString(n - 1);
        return prev + "1" + invertreverse(prev);
    }

    char findKthBit(int n, int k) {
        string s = NthBinaryString(n);
        return s[k - 1];
    }
};
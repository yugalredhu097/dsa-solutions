// Problem: Add Binary
// Link: https://leetcode.com/problems/add-binary/
// Approach: Two Pointers + Carry
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
Given two binary strings `a` and `b`, we need to return their sum
as a binary string.

Approach:
1. Start from the end of both strings.
2. Add corresponding bits along with a carry.
3. Store the result bit and update the carry.
4. Continue until all bits and carry are processed.
5. Reverse the result to obtain the correct binary sum.

This simulates binary addition exactly as done manually.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += (a[i--] - '0');
            if (j >= 0) sum += (b[j--] - '0');

            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

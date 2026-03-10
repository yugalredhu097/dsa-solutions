// Problem: Shifting Letters
// Link: https://leetcode.com/problems/shifting-letters/
// Approach: Suffix Sum
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given a string `s` and an array `shifts`.
For each index i, we must shift the first i+1 characters
of the string to the right by shifts[i] times.

Instead of performing shifts repeatedly, we optimize it
using a suffix sum.

Key Idea:

Each character s[i] will be affected by all shifts[j]
where j >= i.

Steps:

1. Traverse the shifts array from right to left and compute
   a suffix sum that stores the total shifts affecting each index.

2. Since shifting 26 times returns the same character,
   we use modulo 26 to avoid unnecessary large values.

3. For each character:
      new_char = ('a' + (s[i] - 'a' + total_shift) % 26)

4. Update the string with the shifted characters.

This allows us to compute the final string in O(n) time.
*/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = s.size();
        vector<int> suff(n);
        long long sum = 0;

        // Compute suffix sum of shifts
        for (int i = n - 1; i >= 0; i--) {
            sum += shifts[i] % 26;
            suff[i] = sum;
        }

        // Apply shifts to characters
        for (int i = 0; i < n; i++) {
            s[i] = ('a' + (s[i] - 'a' + suff[i]) % 26);
        }

        return s;
    }
};
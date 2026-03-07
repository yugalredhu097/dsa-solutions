// Problem: Minimum Number of Flips to Make the Binary String Alternating
// Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Approach: Sliding Window + Pattern Matching
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We want the binary string to become alternating after any number
of rotations. An alternating string can be either:

1. "010101..."
2. "101010..."

Approach:
1. Duplicate the string to simulate rotations (s = s + s).
2. Create two alternating patterns for length 2*n.
3. Use a sliding window of size n.
4. Track mismatches with both patterns inside the window.
5. Update the minimum flips required.

This ensures we evaluate all possible rotations efficiently.
*/

class Solution {
public:
    int minFlips(string s) {

        int n = s.size();

        string pt1 = "", pt2 = "";

        for (int i = 0; i < 2 * n; i++) {
            if (i % 2 == 0) {
                pt1.push_back('0');
                pt2.push_back('1');
            } else {
                pt1.push_back('1');
                pt2.push_back('0');
            }
        }

        s = s + s;

        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;

        int l = 0, r = 0;

        while (r < 2 * n) {

            if (s[r] != pt1[r]) diff1++;
            if (s[r] != pt2[r]) diff2++;

            if (r - l + 1 > n) {
                if (s[l] != pt1[l]) diff1--;
                if (s[l] != pt2[l]) diff2--;
                l++;
            }

            if (r - l + 1 == n) {
                ans = min({ans, diff1, diff2});
            }

            r++;
        }

        return ans;
    }
};
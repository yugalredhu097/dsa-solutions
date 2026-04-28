// Problem: Minimum Window Subsequence
// Link: https://leetcode.com/problems/minimum-window-subsequence/
// Approach: Two-phase scan (forward match + backward shrink)
// Time Complexity: O(n * m)
// Space Complexity: O(1)

/*
Explanation:
Given strings s1 and s2, we need to find the smallest substring
in s1 such that s2 is a subsequence of that substring.

Approach:
1. Start scanning from each possible index.
2. Move forward to find a subsequence match of s2 in s1.
3. Once found, move backward to shrink the window.
4. Update the best window if it is smaller.
5. Move the starting pointer to search for a better window.

This two-phase scanning ensures we get the minimum window.
*/

class Solution {
public:
    string minWindow(string& s1, string& s2) {
        string temp = "";
        int bestLen = INT_MAX;
        int n = s1.size();
        int m = s2.size();

        int r = 0;

        while (r < n) {
            int cnt = 0;

            // Step 1: forward scan to match subsequence
            int i = r;
            while (i < n) {
                if (s1[i] == s2[cnt]) {
                    cnt++;
                    if (cnt == m) break;
                }
                i++;
            }

            if (cnt < m) break; // no more subsequences possible

            // Step 2: backward shrink
            int end = i;
            cnt = m - 1;
            while (i >= r) {
                if (s1[i] == s2[cnt]) {
                    cnt--;
                    if (cnt < 0) break;
                }
                i--;
            }

            int start = i;

            // update best window
            if (end - start + 1 < bestLen) {
                bestLen = end - start + 1;
                temp = s1.substr(start, bestLen);
            }

            // move start pointer forward
            r = start + 1;
        }

        return temp;
    }
};

// Problem: Minimum Window Substring
// Link: https://leetcode.com/problems/minimum-window-substring/
// Approach: Sliding Window + Frequency Map
// Time Complexity: O(n)
// Space Complexity: O(1) (since alphabet size is limited)

/*
Explanation:
Given two strings s and t, we need to find the smallest substring
of s that contains all characters of t (including duplicates).

Approach:
1. Store the frequency of characters of t in a map.
2. Use a sliding window with two pointers (l and r).
3. Expand the window by moving r and decrease character counts.
4. When all characters of t are matched:
   - Try shrinking the window from the left.
   - Update the minimum window size.
5. Return the smallest valid window found.

If no such window exists, return an empty string.
*/

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mpp;

        // Frequency map for t
        for (char ch : t) {
            mpp[ch]++;
        }

        int l = 0, cnt = 0;
        int minlen = INT_MAX, startIndex = -1;
        int n = s.size();

        for (int r = 0; r < n; r++) {

            if (mpp[s[r]] > 0)
                cnt++;

            mpp[s[r]]--;

            // Try to shrink the window
            while (cnt == t.size()) {

                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    startIndex = l;
                }

                mpp[s[l]]++;
                if (mpp[s[l]] > 0)
                    cnt--;

                l++;
            }
        }

        return (startIndex == -1) ? "" : s.substr(startIndex, minlen);
    }
};

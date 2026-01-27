// Problem: Longest Repeating Character Replacement
// Link: https://leetcode.com/problems/longest-repeating-character-replacement/
// Approach: Sliding Window (fix one character at a time)
// Time Complexity: O(26 * n) ≈ O(n)
// Space Complexity: O(1)

/*
Explanation:
We are allowed to replace at most k characters in a substring
so that all characters become the same.

Approach:
1. For each unique character in the string:
   - Treat it as the target character.
2. Use a sliding window where:
   - We count how many characters in the window are NOT equal
     to the target character.
3. If mismatches exceed k, shrink the window.
4. Track the maximum valid window size.

Since there are at most 26 uppercase characters,
this runs efficiently in linear time.
*/

class Solution {
public:

    // Sliding window for a fixed target character
    int maxforeachchar(string& s, int k, char c) {

        int l = 0, cnt = 0, maxlen = 0;
        int n = s.size();

        for (int r = 0; r < n; r++) {

            if (s[r] != c)
                cnt++;

            while (cnt > k) {
                if (s[l] != c)
                    cnt--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }

    int characterReplacement(string s, int k) {

        set<char> st;
        for (char ch : s)
            st.insert(ch);

        int maxlen = 0;

        for (char ch : st) {
            maxlen = max(maxlen, maxforeachchar(s, k, ch));
        }

        return maxlen;
    }
};

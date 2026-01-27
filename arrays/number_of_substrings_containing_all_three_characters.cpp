// Problem: Number of Substrings Containing All Three Characters
// Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Approach: Sliding Window + Complement Counting
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We need to count the number of substrings that contain
at least one occurrence of each character: 'a', 'b', and 'c'.

Key Idea:
Total substrings = n * (n + 1) / 2

If we subtract the number of substrings that contain
fewer than 3 distinct characters, we get the required answer.

Approach:
1. Calculate the total number of substrings.
2. Use a sliding window to count substrings with < 3 distinct characters.
3. Subtract this count from the total substrings.

This efficiently gives the number of substrings containing
all three characters.
*/

class Solution {
public:
    int numberOfSubstrings(string s) {

        long long n = s.size();
        long long total = (n * (n + 1)) / 2;

        int l = 0;
        long long cnt = 0;
        unordered_map<char, int> mpp;

        for (int r = 0; r < n; r++) {

            mpp[s[r]]++;

            // Shrink window while we have all 3 characters
            while (mpp.size() >= 3) {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                    mpp.erase(s[l]);
                l++;
            }

            // Count substrings with < 3 distinct characters
            cnt += (r - l + 1);
        }

        return total - cnt;
    }
};

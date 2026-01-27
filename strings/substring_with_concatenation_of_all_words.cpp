// Problem: Substring with Concatenation of All Words
// Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Approach: Sliding Window with Hash Maps (fixed word length)
// Time Complexity: O(n * wordLen)
// Space Complexity: O(wordCount)

/*
Explanation:
We are given a string `s` and an array of words `words`,
where all words have the same length.

We need to find all starting indices of substrings in `s`
that are a concatenation of each word in `words` exactly once,
without any extra characters.

Approach:
1. Store the required frequency of each word in a map `need`.
2. Since all words have the same length, try `wordLen` different offsets.
3. For each offset:
   - Use a sliding window that moves in steps of `wordLen`.
   - Maintain a `have` map to track current word frequencies.
   - If a word is not needed, reset the window.
   - If a word appears too many times, shrink the window from the left.
4. When the window contains exactly `wordCount` words,
   record the starting index.

This ensures all valid substrings are found efficiently.
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;
        if (words.empty() || s.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return ans;

        unordered_map<string, int> need;
        for (string& w : words)
            need[w]++;

        // Try all possible offsets
        for (int offset = 0; offset < wordLen; offset++) {

            unordered_map<string, int> have;
            int left = offset;
            int count = 0;

            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word not in required list → reset window
                if (need.find(word) == need.end()) {
                    have.clear();
                    count = 0;
                    left = right + wordLen;
                }
                else {
                    have[word]++;
                    count++;

                    // Too many occurrences → shrink window
                    while (have[word] > need[word]) {
                        string leftWord = s.substr(left, wordLen);
                        have[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Found a valid concatenation
                    if (count == wordCount) {
                        ans.push_back(left);

                        // Move window forward
                        string leftWord = s.substr(left, wordLen);
                        have[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                }
            }
        }

        return ans;
    }
};

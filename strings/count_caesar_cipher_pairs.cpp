// Problem: Count Caesar Cipher Pairs
// Link: https://leetcode.com/problems/count-caesar-cipher-pairs/
// Approach: Hashing using shift-pattern (Caesar cipher normalization)
// Time Complexity: O(n * L)
// Space Complexity: O(n)

/*
Explanation:
Two strings form a Caesar Cipher pair if one string can be obtained
from the other by shifting all characters by the same amount.

Idea:
- For each word, create a normalized "mask" based on character shifts
  relative to the first character.
- If two words have the same mask, they belong to the same Caesar group.

Example:
"abc" → mask: 1#2#
"bcd" → mask: 1#2#
These two form a valid Caesar Cipher pair.

Approach:
1. Generate a shift-pattern mask for each word.
2. Use a hashmap to count occurrences of each mask.
3. For each word, add existing count of the same mask to the answer.
4. Increment the count of the mask.
*/

class Solution {
public:

    // Generate shift-pattern mask for a word
    string maskmaker(string s) {
        string mask = "";
        for (int i = 1; i < s.size(); i++) {
            int diff = (s[i] - s[0] + 26) % 26;
            mask += to_string(diff) + '#';
        }
        return mask;
    }

    long long countPairs(vector<string>& words) {

        unordered_map<string, long long> mpp;
        long long cnt = 0;

        for (int i = 0; i < words.size(); i++) {
            string mask = maskmaker(words[i]);
            cnt += mpp[mask];
            mpp[mask]++;
        }

        return cnt;
    }
};

// Problem: Vowel-Consonant Score (LeetCode 3813)
// Link: https://leetcode.com/problems/vowel-consonant-score/
// Approach: Simple counting
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
- Iterate through the string.
- Ignore spaces and digits.
- Count vowels and consonants separately.
- Score is defined as: floor(vowels / consonants)
- If consonant count is 0, return 0.
*/

class Solution {
public:
    bool isvowel(string &vowels, char a) {
        for (int i = 0; i < vowels.size(); i++) {
            if (vowels[i] == a) return true;
        }
        return false;
    }

    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        string vowels = "aeiou";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' || (s[i] >= '0' && s[i] <= '9')) continue;

            if (isvowel(vowels, s[i])) v++;
            else c++;
        }

        return (c > 0) ? (v / c) : 0;
    }
};

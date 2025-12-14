// Problem: Reverse Words With Same Vowel Count
// Link: https://leetcode.com/problems/reverse-words-with-same-vowel-count/
// Approach: String traversal + vowel counting
// Time Complexity: O(n^2) (due to substring + vowel checks)
// Space Complexity: O(1)

/*
Explanation:
Given a string of words separated by spaces:

1. Count the number of vowels in the first word.
2. For every other word:
   - Count its vowels.
   - If vowel count matches the first word's vowel count,
     reverse that word in-place.
3. Return the modified string.

We use helper functions:
- isvowel(): checks if a character is a vowel
- numberofvowels(): counts vowels in a word
- reverse(): reverses characters in a given range

Vowels considered: a, e, i, o, u
*/

class Solution {
public:

    // Reverse characters in string from index i to j
    void reverse(string &s, int i, int j) {
        while (i <= j) {
            swap(s[i++], s[j--]);
        }
    }

    // Check if character is a vowel
    bool isvowel(char c, string &vowels) {
        for (int i = 0; i < vowels.size(); i++) {
            if (c == vowels[i]) return true;
        }
        return false;
    }

    // Count number of vowels in a string
    int numberofvowels(string temp, string &vowels) {
        int cnt = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (isvowel(temp[i], vowels))
                cnt++;
        }
        return cnt;
    }

    string reverseWords(string s) {

        int i = 0;
        int n = s.length();
        string vowels = "aeiou";

        // Step 1: Count vowels in first word
        int vowelCount = 0;
        while (i < n && s[i] != ' ') {
            if (isvowel(s[i], vowels))
                vowelCount++;
            i++;
        }

        i++; // move past space

        // Step 2: Process remaining words
        while (i < n) {
            int j = i;

            // Find end of current word
            while (j < n && s[j] != ' ')
                j++;

            // Count vowels in current word
            int currVowels = numberofvowels(s.substr(i, j - i), vowels);

            // Reverse if vowel counts match
            if (currVowels == vowelCount)
                reverse(s, i, j - 1);

            i = j + 1;
        }

        return s;
    }
};

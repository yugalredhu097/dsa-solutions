// Problem: Reverse Words in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Approach: Reverse whole string + reverse each word in-place
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We are given a string that may contain:
- Leading spaces
- Trailing spaces
- Multiple spaces between words

Goal:
Reverse the order of words and return a string with:
- Single space between words
- No leading/trailing spaces

Approach:
1. Reverse the entire string.
2. Traverse the string and copy words one by one to the front.
3. Reverse each word individually to restore correct word order.
4. Resize the string to remove extra characters.

This solution works in-place with O(1) extra space.
*/

class Solution {
public:

    // Reverse characters in a given range
    void reverse(string &s, int l, int r) {
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }

    string reverseWords(string s) {
        int n = s.size();

        // Step 1: Reverse entire string
        reverse(s, 0, n - 1);

        int idx = 0;  // write pointer
        int i = 0;

        // Step 2: Process each word
        while (i < n) {

            // Skip spaces
            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)
                break;

            // Add space before word (except first word)
            if (idx > 0)
                s[idx++] = ' ';

            int start = idx;

            // Copy the word
            while (i < n && s[i] != ' ') {
                s[idx++] = s[i++];
            }

            // Reverse the copied word
            reverse(s, start, idx - 1);
        }

        // Trim extra characters
        s.resize(idx);
        return s;
    }
};

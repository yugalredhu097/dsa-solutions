// Problem: Mirror Frequency Distance
// Link: https://leetcode.com/problems/mirror-frequency-distance/
// Approach: Frequency Map + Mirror Character Mapping
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:

We are given a string s containing:
- lowercase letters OR digits

Goal:
For each character, find its "mirror" character and compute
the absolute difference in their frequencies.

------------------------------------------------

Mirror Definition:

1. For lowercase letters:
   mirror(c) = 'a' + ('z' - c)

   Example:
   a ↔ z
   b ↔ y

2. For digits:
   mirror(c) = '0' + ('9' - c)

   Example:
   0 ↔ 9
   1 ↔ 8

------------------------------------------------

Approach:

1. Count frequency of all characters.

2. Traverse the string:
   - For each character, find its mirror
   - Add |freq[c] - freq[mirror]| only once per pair

3. Use a visited set to avoid double counting.

------------------------------------------------

Example:

s = "abzy"

Pairs:
a ↔ z
b ↔ y

Compute:
|freq[a] - freq[z]| + |freq[b] - freq[y]|

------------------------------------------------
*/

class Solution {
public:
    int mirrorFrequency(string s) {

        unordered_map<char, int> mpp;

        // Count frequency
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }

        int sum = 0;
        unordered_set<char> visited;

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];
            char mirror;

            // Find mirror character
            if (c >= 'a' && c <= 'z') {
                mirror = 'a' + ('z' - c);
            }
            else {
                mirror = '0' + ('9' - c);
            }

            // Avoid double counting
            if (!visited.count(c) && !visited.count(mirror)) {
                sum += abs(mpp[c] - mpp[mirror]);
            }

            visited.insert(c);
            visited.insert(mirror);
        }

        return sum;
    }
};
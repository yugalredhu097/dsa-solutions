// Problem: Isomorphic Strings
// Link: https://leetcode.com/problems/isomorphic-strings/
// Approach: Hash Map Mapping (Two-way Mapping)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:

Two strings s and t are isomorphic if the characters in s
can be replaced to get t while preserving the order of characters.

Rules:
- Each character must map to exactly one character.
- No two characters can map to the same character.

Key Idea:

We maintain a mapping from characters in s → characters in t.

Steps:

1. Traverse both strings.
2. If a character from s already exists in the map:
      check if it maps to the current character in t.
      If not, return false.
3. Otherwise create the mapping.

To ensure a valid one-to-one mapping,
we repeat the same process from t → s.

If both mappings are valid, the strings are isomorphic.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mpp;

        // Mapping s -> t
        for (int i = 0; i < s.size(); i++) {

            if (mpp.find(s[i]) != mpp.end()) {
                if (mpp[s[i]] != t[i])
                    return false;
            }
            else {
                mpp[s[i]] = t[i];
            }
        }

        mpp.clear();

        // Mapping t -> s
        for (int i = 0; i < s.size(); i++) {

            if (mpp.find(t[i]) != mpp.end()) {
                if (mpp[t[i]] != s[i])
                    return false;
            }
            else {
                mpp[t[i]] = s[i];
            }
        }

        return true;
    }
};
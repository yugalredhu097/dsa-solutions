// Problem: Count Residue Prefixes
// LeetCode: 3803
// Link: https://leetcode.com/problems/count-residue-prefixes/
// Approach: Prefix processing with set
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
For each prefix of the string:
- Let the prefix length be (i + 1).
- Compute (i + 1) % 3.
- If the number of distinct characters in the prefix
  equals this value, it is counted as a residue prefix.

Approach:
1. Traverse the string character by character.
2. Maintain a set to track distinct characters seen so far.
3. At each index i:
   - Check if distinct count == (i + 1) % 3
4. If yes, increment the residue count.
*/

class Solution {
public:
    int residuePrefixes(string s) {

        int residue = 0;
        unordered_set<char> seen;

        for (int i = 0; i < s.size(); i++) {
            seen.insert(s[i]);

            if (seen.size() == (i + 1) % 3)
                residue++;
        }

        return residue;
    }
};

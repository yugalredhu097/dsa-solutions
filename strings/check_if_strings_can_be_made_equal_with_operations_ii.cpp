// Problem: Check if Strings Can be Made Equal With Operations II
// Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/
// Approach: Frequency Counting on Even and Odd Indices
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:

We are given two strings s1 and s2.

Goal:
Check if we can make s1 equal to s2 using allowed operations.

------------------------------------------------

Key Observation:

We can swap characters:
- Among even indices
- Among odd indices

So:
- Characters at even positions can only rearrange among themselves
- Characters at odd positions can only rearrange among themselves

------------------------------------------------

Approach:

1. Check overall frequency:
   If total frequency differs → return false

2. Check even indices:
   Compare frequency of characters at even positions

3. Check odd indices:
   Compare frequency of characters at odd positions

4. If all match → return true

------------------------------------------------

Example:

s1 = "abcd"
s2 = "cdab"

Even indices → must match
Odd indices  → must match

------------------------------------------------

This ensures valid transformations.
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {

        unordered_map<char,int> mpp1, mpp2;

        // Check overall frequency
        for (int i = 0; i < s1.size(); i++) {
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }

        if (mpp1 != mpp2)
            return false;

        mpp1.clear();
        mpp2.clear();

        // Check even indices
        for (int i = 0; i < s1.size(); i += 2) {
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }

        if (mpp1 != mpp2)
            return false;

        mpp1.clear();
        mpp2.clear();

        // Check odd indices
        for (int i = 1; i < s1.size(); i += 2) {
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }

        if (mpp1 != mpp2)
            return false;

        return true;
    }
};
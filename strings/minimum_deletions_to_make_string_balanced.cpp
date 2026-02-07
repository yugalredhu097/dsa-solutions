// Problem: Minimum Deletions to Make String Balanced
// Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Approach: Prefix–Suffix Count
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
A string is considered balanced if there is no 'b' appearing
before any 'a'. In other words, all 'a's must come before all 'b's.

Approach:
1. Count total number of 'a's in the string.
2. Traverse the string from left to right.
3. Maintain:
   - remaining 'a's on the right
   - number of 'b's on the left
4. At each position, compute deletions needed:
   deletions = remainingA + leftB
5. Track the minimum deletions across all positions.

This greedy approach finds the optimal split point.
*/

class Solution {
public:
    int minimumDeletions(string s) {
        int remainingA = 0;

        // Count total 'a's
        for (char c : s) {
            if (c == 'a') remainingA++;
        }

        int leftB = 0;
        int ans = s.size();

        for (char c : s) {
            ans = min(ans, remainingA + leftB);

            if (c == 'a') remainingA--;
            else leftB++;
        }

        ans = min(ans, remainingA + leftB);
        return ans;
    }
};

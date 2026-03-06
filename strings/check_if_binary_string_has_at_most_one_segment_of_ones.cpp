// Problem: Check if Binary String Has at Most One Segment of Ones
// Link: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// Approach: Segment Counting
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
A segment of ones is a contiguous group of '1's in the string.

The task is to determine whether the string contains
at most one such segment.

Approach:
1. Traverse the string.
2. When encountering '1', count the segment and skip all
   consecutive '1's.
3. Skip sequences of '0's normally.
4. If more than one segment of '1's is found, return false.
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        int n = s.size();
        int cnt = 0;

        while (i < n) {
            if (s[i] == '0') {
                while (i < n && s[i] == '0') {
                    i++;
                }
            } else {
                while (i < n && s[i] == '1') {
                    i++;
                }
                cnt++;
            }
        }

        return cnt <= 1;
    }
};
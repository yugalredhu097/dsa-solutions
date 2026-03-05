// Problem: Minimum Changes to Make Alternating Binary String
// Link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Approach: Greedy / Pattern Checking
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We want the binary string to become alternating.

There are only two valid patterns:
1. "010101..."
2. "101010..."

Approach:
1. Count the number of changes needed to convert the string
   into pattern "010101...".
2. Count the number of changes needed to convert the string
   into pattern "101010...".
3. Return the minimum of the two counts.
*/

class Solution {
public:
    int minOperations(string s) {

        int cnt1 = 0;
        bool flag = true;

        // Pattern starting with '0'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (flag == true) flag = false;
                else {
                    cnt1++;
                    flag = true;
                }
            }
            else {
                if (flag == false) flag = true;
                else {
                    cnt1++;
                    flag = false;
                }
            }
        }

        int cnt2 = 0;
        flag = false;

        // Pattern starting with '1'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (flag == true) flag = false;
                else {
                    cnt2++;
                    flag = true;
                }
            }
            else {
                if (flag == false) flag = true;
                else {
                    cnt2++;
                    flag = false;
                }
            }
        }

        return min(cnt1, cnt2);
    }
};
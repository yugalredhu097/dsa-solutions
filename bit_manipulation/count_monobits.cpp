// Problem: Count Monobits
// Link: https://leetcode.com/problems/count-monobits/
// Approach: Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
A number is considered a monobit number if its binary representation
consists of all 1s (e.g., 1 -> 1, 3 -> 11, 7 -> 111).

Property:
A number `i` is a monobit number if:
(i & (i + 1)) == 0

Approach:
1. Iterate from 0 to n.
2. Count numbers that are either 0 or satisfy the monobit condition.
3. Return the total count.

This uses a well-known bitwise trick to efficiently identify monobit numbers.
*/

class Solution {
public:
    int countMonobit(int n) {
        int cnt = 0;

        for (int i = 0; i <= n; i++) {
            if (i == 0 || ((i & (i + 1)) == 0)) {
                cnt++;
            }
        }

        return cnt;
    }
};

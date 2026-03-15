// Problem: Count Commas in Range II
// Link: https://leetcode.com/problems/count-commas-in-range-ii/
// Approach: Mathematical Threshold Counting
// Time Complexity: O(log₁₀₀₀(n))
// Space Complexity: O(1)

/*
Explanation:

When numbers are written with comma formatting:

1 - 999                → 0 commas
1,000 - 999,999        → 1 comma
1,000,000 - 999,999,999 → 2 commas
1,000,000,000 ...      → 3 commas

Instead of formatting every number individually,
we count how many numbers cross each comma threshold.

Key Idea:

Comma positions occur at powers of 1000:

1,000
1,000,000
1,000,000,000
...

For each threshold T:

Every number from T to n contributes
one additional comma.

So we add:
(n - T + 1)

Then move to the next threshold by multiplying
the threshold by 1000.

Example:

n = 5000

Threshold = 1000

Numbers with commas:
1000 → 5000

Count:
5000 - 1000 + 1 = 4001
*/

class Solution {
public:
    long long countCommas(long long n) {

        long long result = 0;
        long long threshold = 1000;

        while (threshold <= n) {
            result += (n - threshold + 1);
            threshold *= 1000;
        }

        return result;
    }
};
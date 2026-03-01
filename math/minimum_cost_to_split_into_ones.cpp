// Problem: Minimum Cost to Split into Ones
// Link: https://leetcode.com/problems/minimum-cost-to-split-into-ones/
// Approach: Mathematical Formula
// Time Complexity: O(1)
// Space Complexity: O(1)

/*
Explanation:
To split a number `n` into `n` ones, we need to perform splits.
Each split increases the total cost by the current number of parts.

Observation:
The total cost is equivalent to the sum:
1 + 2 + 3 + ... + (n - 1)

This is the well-known arithmetic series:
(n * (n - 1)) / 2
*/

class Solution {
public:
    int minCost(int n) {
        return (n * (n - 1)) / 2;
    }
};
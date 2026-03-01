// Problem: Partitioning Into Minimum Number of Deci-Binary Numbers
// Link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Approach: Greedy / Digit Observation
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
A deci-binary number consists only of digits 0 or 1.
To represent a number `n` as a sum of deci-binary numbers,
each digit in the sum cannot exceed the number of deci-binary numbers used.

Key Observation:
The minimum number of deci-binary numbers required is equal to
the maximum digit present in the string.

Why?
Because that digit needs to be formed by summing 1s from multiple deci-binary numbers.

Approach:
1. Traverse the string.
2. Track the maximum digit.
3. Return it as the answer.
*/

class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;
        for (char c : n) {
            maxi = max(maxi, c - '0');
        }
        return maxi;
    }
};
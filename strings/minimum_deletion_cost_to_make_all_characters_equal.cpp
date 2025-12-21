// Problem: Minimum Deletion Cost to Make All Characters Equal
// Link: https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/
// Approach: Try keeping each unique character and delete the rest
// Time Complexity: O(n * unique_chars)
// Space Complexity: O(unique_chars)

/*
Explanation:
We are given:
- A string `s`
- An array `cost` where cost[i] is the cost to delete s[i]

Goal:
Delete characters so that all remaining characters in the string are equal,
while minimizing the total deletion cost.

Approach:
1. Collect all unique characters in the string.
2. For each unique character `keep`:
   - Assume this character will remain.
   - Delete all other characters and sum their costs.
3. Return the minimum cost among all choices.

Since the number of unique characters is small,
this brute-force approach is efficient.
*/

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {

        // Required by problem statement
        string serivaldan = s;

        // Collect unique characters
        set<char> st;
        for (char c : s) {
            st.insert(c);
        }

        long long mini = LLONG_MAX;

        // Try keeping each character
        for (char keep : st) {
            long long sum = 0;

            for (int i = 0; i < s.size(); i++) {
                if (s[i] != keep) {
                    sum += cost[i];
                }
            }

            mini = min(mini, sum);
        }

        return mini;
    }
};

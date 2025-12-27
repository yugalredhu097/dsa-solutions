// Problem: Minimum Penalty for a Shop
// Link: https://leetcode.com/problems/minimum-penalty-for-a-shop/
// Approach: Prefix + Suffix Penalty Calculation
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We are given a string `customers` where:
- 'Y' means a customer comes at that hour
- 'N' means no customer comes

If the shop closes at hour i:
- All 'N' before i contribute to penalty
- All 'Y' after i contribute to penalty

Approach:
1. Build a prefix array:
   prefix[i] = number of 'N' from index 0 to i
2. Build a suffix array:
   suffix[i] = number of 'Y' from index i to n-1
3. Penalty at hour i = prefix[i] + suffix[i]
4. Find the minimum penalty and return the earliest hour
   that gives this minimum penalty.

Edge Case:
If closing at hour n gives lower penalty, return n.
*/

class Solution {
public:

    // Count total number of 'N'
    int sum(string &customers) {
        int cnt = 0;
        for (char c : customers) {
            if (c == 'N')
                cnt++;
        }
        return cnt;
    }

    int bestClosingTime(string customers) {

        int n = customers.size();
        vector<int> prefix(n), suffix(n), penalty(n);

        // Prefix: count of 'N' before or at i
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            prefix[i] = cnt;
            if (customers[i] == 'N')
                cnt++;
        }

        // Suffix: count of 'Y' after i
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = cnt;
            if (customers[i] == 'Y')
                cnt++;
        }

        // Compute penalties
        int minPenalty = INT_MAX;
        for (int i = 0; i < n; i++) {
            penalty[i] = prefix[i] + suffix[i];
            minPenalty = min(minPenalty, penalty[i]);
        }

        // Check closing after last hour
        int closeAfterAll = sum(customers);
        if (closeAfterAll < minPenalty)
            return n;

        // Find earliest hour with minimum penalty
        for (int i = 0; i < n; i++) {
            if (penalty[i] == minPenalty)
                return i;
        }

        return n;
    }
};

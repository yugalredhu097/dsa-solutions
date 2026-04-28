// Problem: Minimum Number of Days to Make m Bouquets
// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Approach: Binary Search on Answer + feasibility check
// Time Complexity: O(n log max(bloomDay))
// Space Complexity: O(1)

/*
Explanation:
We need to determine the minimum day on which it is possible to make
`m` bouquets. Each bouquet requires choosing `k` adjacent flowers that
have already bloomed.

Key Observations:
1. The answer lies between:
      minimum day = 1
      maximum day = max(bloomDay)

2. For any given number of days X, we can check feasibility:
   - Traverse bloomDay
   - Count consecutive flowers where bloomDay[i] <= X
   - Every k consecutive flowers form 1 bouquet
   - Reset counter when encountering a flower that blooms after X

3. Use binary search:
   - If possible in X days → try a smaller X
   - Otherwise → increase X

4. If total flowers < m*k → impossible → return -1
*/

class Solution {
public:

    // Check if we can make m bouquets in 'days' days
    bool ispossible(vector<int>& bloomDay, int days, int m, int k) {
        int cnt = 0;         // consecutive bloomed flowers
        int bouquets = 0;    // bouquets formed
        int n = bloomDay.size();

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= days) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        // Add last streak
        bouquets += cnt / k;

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long required = 1LL * m * k;
        if (required > bloomDay.size())
            return -1;   // not enough flowers available

        int s = 1;
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (ispossible(bloomDay, mid, m, k)) {
                ans = mid;
                e = mid - 1;   // try smaller days
            } else {
                s = mid + 1;   // need more days
            }
        }

        return ans;
    }
};

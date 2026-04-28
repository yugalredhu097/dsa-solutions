// Problem: Total Score of Dungeon Runs
// Link: https://leetcode.com/problems/total-score-of-dungeon-runs/
// Approach: Prefix Sum + Binary Search
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
We are given:
- `damage` array representing damage taken in each dungeon run
- `requirement` array representing the minimum remaining health requirement
- initial health `hp`

Approach:
1. Build a prefix sum array of damage.
2. For each position i:
   - Calculate the target prefix value needed to satisfy the health condition.
3. Use binary search (lower_bound) to find the earliest valid prefix.
4. Count valid runs contributing to the total score.

Prefix sums allow fast damage calculations,
and binary search efficiently finds valid segments.
*/

class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {

        int n = damage.size();

        vector<long long> pref(n + 1, 0);

        // Build prefix sum of damage
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + damage[i - 1];
        }

        long long ans = 0;

        for (int i = 1; i <= n; i++) {

            long long target = pref[i] - hp + requirement[i - 1];

            int pos = lower_bound(pref.begin(), pref.begin() + i, target) - pref.begin();

            ans += (i - pos);
        }

        return ans;
    }
};
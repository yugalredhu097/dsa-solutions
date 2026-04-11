// Problem: Minimum Distance Between Three Equal Elements II
// Link: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
// Approach: Sorting + Triplet Check
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:

We are given an array nums.

Goal:
Find three indices i, j, k such that:
nums[i] == nums[j] == nums[k]

Minimize:
|i - j| + |j - k| + |i - k|

------------------------------------------------

Key Idea:

1. Store (value, index) pairs.
2. Sort by value so equal elements come together.
3. For every group of equal values:
   - Check consecutive triplets
   - Compute distance using indices

------------------------------------------------

Why sorting?

It groups identical values together,
making it easy to check triplets.

------------------------------------------------

Steps:

1. Build vector of (value, index)
2. Sort by value
3. Traverse and check triples with same value
4. Track minimum distance

------------------------------------------------

Return:
- Minimum distance if exists
- Otherwise → -1
*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        vector<pair<int,int>> v;

        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int mini = INT_MAX;
        int n = v.size();

        for (int i = 0; i + 2 < n; i++) {

            if (v[i].first == v[i+1].first &&
                v[i+1].first == v[i+2].first) {

                int d = abs(v[i].second - v[i+1].second)
                      + abs(v[i+1].second - v[i+2].second)
                      + abs(v[i].second - v[i+2].second);

                mini = min(mini, d);
            }
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};
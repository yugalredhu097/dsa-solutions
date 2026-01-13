// Problem: Trapping Rain Water
// Link: https://leetcode.com/problems/trapping-rain-water/
// Approach: Prefix Max & Suffix Max Arrays
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
Water trapped at an index i depends on:
- The maximum height to the left of i
- The maximum height to the right of i

Water at i = min(maxLeft[i], maxRight[i]) - height[i]

Approach:
1. Build an array ngel[] storing the maximum height to the left.
2. Build an array nger[] storing the maximum height to the right.
3. For each index, compute trapped water using the formula above.
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        vector<int> ngel(n), nger(n);

        int maxLeft = 0, maxRight = 0;

        // Build left max array
        for (int i = 0; i < n; i++) {
            maxLeft = max(maxLeft, height[i]);
            ngel[i] = maxLeft;
        }

        // Build right max array
        for (int i = n - 1; i >= 0; i--) {
            maxRight = max(maxRight, height[i]);
            nger[i] = maxRight;
        }

        int water = 0;

        // Calculate trapped water
        for (int i = 0; i < n; i++) {
            water += min(ngel[i], nger[i]) - height[i];
        }

        return water;
    }
};

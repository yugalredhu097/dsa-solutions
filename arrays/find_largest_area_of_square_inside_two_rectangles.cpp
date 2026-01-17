// Problem: Find the Largest Area of Square Inside Two Rectangles (LeetCode 3047)
// Link: https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/
// Approach: Check overlap between every pair of rectangles
// Time Complexity: O(n^2)
// Space Complexity: O(1)

/*
Explanation:
Each rectangle is defined by bottomLeft and topRight coordinates.

For every pair of rectangles:
- Compute overlapping width:
    min(x2_right, x1_right) - max(x2_left, x1_left)
- Compute overlapping height:
    min(y2_top, y1_top) - max(y2_bottom, y1_bottom)

If both overlap dimensions are positive:
- The largest possible square side = min(overlapWidth, overlapHeight)
- Area = side * side

Track the maximum square area across all pairs.
*/

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                long long overlapWidth =
                    min(topRight[i][0], topRight[j][0]) -
                    max(bottomLeft[i][0], bottomLeft[j][0]);

                long long overlapHeight =
                    min(topRight[i][1], topRight[j][1]) -
                    max(bottomLeft[i][1], bottomLeft[j][1]);

                if (overlapWidth > 0 && overlapHeight > 0) {
                    long long side = min(overlapWidth, overlapHeight);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};

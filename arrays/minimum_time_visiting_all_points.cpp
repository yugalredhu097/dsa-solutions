// Problem: Minimum Time Visiting All Points
// Link: https://leetcode.com/problems/minimum-time-visiting-all-points/
// Approach: Greedy (Chebyshev Distance)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We are given a list of points on a 2D plane.
In one second, we can move:
- Vertically
- Horizontally
- Diagonally

To move from point A to point B:
- dx = |x2 - x1|
- dy = |y2 - y1|
The minimum time required is max(dx, dy).

Why?
- We can cover one unit in both x and y directions simultaneously
  using diagonal moves.
- Remaining distance (if any) is covered by straight moves.

So, for each consecutive pair of points:
time += max(dx, dy)
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int time = 0;

        for (int i = 1; i < points.size(); i++) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            time += max(dx, dy);
        }

        return time;
    }
};

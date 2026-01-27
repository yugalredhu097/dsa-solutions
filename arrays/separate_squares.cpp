// Problem: Separate Squares
// Link: https://leetcode.com/problems/separate-squares/
// Approach: Binary Search on Answer (Geometry)
// Time Complexity: O(n * log(range))
// Space Complexity: O(1)

/*
Explanation:
We are given multiple squares, each represented as:
[x, y, side]

We need to find a horizontal line (y = k) such that:
- The total area of square parts below the line
  equals the total area of square parts above the line.

Approach:
1. Binary search on the y-coordinate (k).
2. For a candidate k:
   - Compute area below the line (area1)
   - Compute area above the line (area2)
3. If area2 > area1 → move the line upward
   Else → move the line downward
4. Stop when the difference is within a small epsilon.
*/

class Solution {
public:

    // Returns (area_above - area_below) for a given horizontal line y = k
    double isvalid(double k, vector<vector<int>>& squares) {

        double areaBelow = 0;
        double areaAbove = 0;

        for (int i = 0; i < squares.size(); i++) {

            double y = squares[i][1];
            double side = squares[i][2];
            double top = y + side;

            // Entire square below the line
            if (top <= k) {
                areaBelow += side * side;
            }
            // Square intersects the line
            else if (y < k) {
                areaBelow += (k - y) * side;
                areaAbove += (top - k) * side;
            }
            // Entire square above the line
            else {
                areaAbove += side * side;
            }
        }

        return areaAbove - areaBelow;
    }

    double separateSquares(vector<vector<int>>& squares) {

        double minY = 1e18, maxY = -1e18;

        // Determine search boundaries
        for (auto &sq : squares) {
            minY = min(minY, (double)sq[1]);
            maxY = max(maxY, (double)sq[1] + sq[2]);
        }

        double eps = 1e-5;

        // Binary search on y-coordinate
        while (maxY - minY > eps) {
            double mid = minY + (maxY - minY) / 2.0;
            double diff = isvalid(mid, squares);

            if (diff > 0)
                minY = mid;
            else
                maxY = mid;
        }

        return minY;
    }
};

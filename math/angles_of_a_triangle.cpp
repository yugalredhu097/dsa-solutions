// Problem: Angles of a Triangle
// Link: https://leetcode.com/problems/angles-of-a-triangle/
// Approach: Law of Cosines
// Time Complexity: O(1)
// Space Complexity: O(1)

/*
Explanation:

We are given three side lengths of a triangle.

Goal:
Return the three internal angles in ascending order.

------------------------------------------------

Step 1: Check Valid Triangle

Triangle is valid if:
a + b > c
b + c > a
a + c > b

------------------------------------------------

Step 2: Use Law of Cosines

cos(A) = (b² + c² - a²) / (2bc)
cos(B) = (a² + c² - b²) / (2ac)
cos(C) = (a² + b² - c²) / (2ab)

Angle = acos(value) * (180 / PI)

------------------------------------------------

Step 3: Clamp values

Due to floating point errors:
cos value must be in [-1, 1]

------------------------------------------------

Step 4: Sort angles

Return in ascending order.

------------------------------------------------

If triangle is invalid:
Return empty array.
*/

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

        vector<double> ans;

        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        // Check triangle validity
        if (a + b > c && b + c > a && a + c > b) {

            const double PI = acos(-1);

            double A = ((b*b + c*c) - (a*a)) / (2 * b * c);
            double B = ((a*a + c*c) - (b*b)) / (2 * a * c);
            double C = ((a*a + b*b) - (c*c)) / (2 * a * b);

            // Clamp values to [-1, 1]
            A = max(-1.0, min(1.0, A));
            B = max(-1.0, min(1.0, B));
            C = max(-1.0, min(1.0, C));

            // Convert to degrees
            A = acos(A) * 180.0 / PI;
            B = acos(B) * 180.0 / PI;
            C = acos(C) * 180.0 / PI;

            ans.push_back(A);
            ans.push_back(B);
            ans.push_back(C);

            sort(ans.begin(), ans.end());
        }

        return ans;
    }
};
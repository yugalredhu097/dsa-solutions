// Problem: Trapping Rain Water
// Link: https://leetcode.com/problems/trapping-rain-water/
// Approach: Two Pointers (Optimized Space)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
Water trapped depends on the minimum of the maximum heights
to the left and right of an index.

Optimized Approach:
- Use two pointers (left & right).
- Maintain leftMax and rightMax.
- Move the pointer with the smaller height.
- Calculate trapped water on the fly.

This avoids extra space used in prefix/suffix arrays.
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            if (height[left] <= height[right]) {

                if (height[left] < leftMax)
                    totalWater += leftMax - height[left];
                else
                    leftMax = height[left];

                left++;
            }
            else {

                if (height[right] < rightMax)
                    totalWater += rightMax - height[right];
                else
                    rightMax = height[right];

                right--;
            }
        }

        return totalWater;
    }
};

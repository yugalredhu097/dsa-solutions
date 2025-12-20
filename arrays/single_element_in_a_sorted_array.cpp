// Problem: Single Element in a Sorted Array
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Approach: Binary Search using index parity
// Time Complexity: O(log n)
// Space Complexity: O(1)

/*
Explanation:
In a sorted array where every element appears exactly twice
except one element that appears only once:

Key Observation:
- Pairs before the single element start at even index.
- Pairs after the single element start at odd index.

Algorithm:
1. Use binary search.
2. Always make mid even to compare mid and mid + 1.
3. If nums[mid] == nums[mid + 1], the single element lies on the right.
4. Otherwise, it lies on the left (including mid).

This approach works in logarithmic time with constant space.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // Ensure mid is even
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1]) {
                s = mid + 2;
            } else {
                e = mid;
            }
        }

        return nums[s];
    }
};

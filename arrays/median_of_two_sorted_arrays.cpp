// Problem: Median of Two Sorted Arrays
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Approach: Merge two sorted arrays then find median
// Time Complexity: O(m + n)
// Space Complexity: O(m + n)

/*
Explanation:
We have two sorted arrays. The simplest approach is:

1. Merge both arrays into a single sorted array using two pointers.
2. Compute the median:
   - If total size is odd, median is middle element.
   - If even, median is the average of the two middle elements.

This approach uses extra space but is easy to implement and understand.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i = 0, j = 0;
        vector<int> temp;

        int m = nums1.size();
        int n = nums2.size();

        // Merge two sorted arrays
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements
        while (i < m) {
            temp.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            temp.push_back(nums2[j]);
            j++;
        }

        // Find median
        int k = temp.size();
        double median = 0;

        if (k % 2 == 0) {
            median = (temp[k/2 - 1] + temp[k/2]) / 2.0;
        } else {
            median = temp[k/2];
        }

        return median;
    }
};

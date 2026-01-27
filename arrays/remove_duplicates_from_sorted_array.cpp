// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Approach: Two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
Given a sorted array, we need to remove duplicates in-place
such that each unique element appears only once.

Approach:
1. Use two pointers:
   - i to traverse the array
   - k to track the position of the next unique element
2. For each group of duplicate elements:
   - Place the unique element at index k
   - Increment k
3. Return k, which represents the number of unique elements.

The array is modified in-place as required.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        int k = 0;

        while (i < n) {
            int j = i + 1;

            // Skip duplicates
            while (j < n && nums[j] == nums[i]) {
                j++;
            }

            nums[k] = nums[i];
            k++;
            i = j;
        }

        return k;
    }
};

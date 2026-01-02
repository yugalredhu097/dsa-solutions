// Problem: N-Repeated Element in Size 2N Array
// Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Approach: Observation-based linear scan
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
In an array of size 2N, one element is repeated exactly N times,
while all other elements appear only once.

Key Observation:
The repeated element must appear at least twice within
any window of size 3.

Approach:
1. Traverse the array.
2. Check if nums[i] equals nums[i+1] or nums[i+2].
3. If found, return nums[i].
4. If not found in the loop, the last element must be the answer.

This avoids using extra space and works in linear time.
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) {
                return nums[i];
            }
        }

        return nums[n - 1];
    }
};

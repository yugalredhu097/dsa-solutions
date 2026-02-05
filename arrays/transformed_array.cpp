// Problem: Transformed Array
// Link: https://leetcode.com/problems/transformed-array/
// Approach: Circular index simulation using modulo
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
Given an integer array `nums`, construct a transformed array `result`
based on the following rules:

- If nums[i] > 0:
  Move nums[i] steps forward circularly and take that element.
- If nums[i] < 0:
  Move |nums[i]| steps backward circularly and take that element.
- If nums[i] == 0:
  result[i] = nums[i].

Approach:
1. Iterate through each index of the array.
2. Use modulo arithmetic to handle circular movement.
3. Adjust negative indices by adding `n` to keep them in range.
4. Store the computed value in the result array.

This direct simulation ensures correctness with linear time complexity.
*/

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[i] = nums[(i + nums[i]) % n];
            }
            else if (nums[i] < 0) {
                int idx = (i - abs(nums[i])) % n;
                if (idx < 0) idx += n;
                result[i] = nums[idx];
            }
            else {
                result[i] = nums[i];
            }
        }

        return result;
    }
};

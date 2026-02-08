// Problem: Merge Adjacent Equal Elements
// Link: https://leetcode.com/problems/merge-adjacent-equal-elements/
// Approach: Stack-like simulation using vector
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
Given an array, we repeatedly merge adjacent equal elements.
Whenever two adjacent elements are equal:
- Remove one of them.
- Double the value of the remaining element.

Approach:
1. Use a vector as a stack-like structure.
2. Traverse the input array:
   - Push each element into the result vector.
3. After each push:
   - While the last two elements are equal:
     - Remove the last element.
     - Double the new last element.
4. Continue until no adjacent equal elements remain.

This simulates the merging process efficiently in one pass.
*/

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;

        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[i]);

            // Merge while last two elements are equal
            while (ans.size() >= 2 &&
                   ans[ans.size() - 1] == ans[ans.size() - 2]) {
                long long val = ans.back();
                ans.pop_back();
                ans.back() += val;
            }
        }

        return ans;
    }
};

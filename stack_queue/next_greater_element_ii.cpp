// Problem: Next Greater Element II
// Link: https://leetcode.com/problems/next-greater-element-ii/
// Approach: Monotonic Stack with Circular Traversal
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
This is a circular array version of the Next Greater Element problem.

Key Idea:
- We simulate circular traversal by iterating from 2*n - 1 to 0.
- Use modulo (i % n) to access elements circularly.
- Maintain a monotonic decreasing stack.

Steps:
1. Traverse from right to left (2*n - 1 → 0).
2. Pop elements from the stack that are smaller or equal to the current element.
3. If i < n, assign the next greater element.
4. Push the current element onto the stack.
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            if (i < n) {
                nge[i] = st.empty() ? -1 : st.top();
            }

            st.push(nums[i % n]);
        }

        return nge;
    }
};

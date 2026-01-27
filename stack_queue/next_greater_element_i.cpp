// Problem: Next Greater Element I
// Link: https://leetcode.com/problems/next-greater-element-i/
// Approach: Monotonic Stack + Hash Map
// Time Complexity: O(n + m)
// Space Complexity: O(n)

/*
Explanation:
We are given two arrays:
- nums1 is a subset of nums2.
- For each element in nums1, we need to find its next greater element
  in nums2 (to the right side).

Approach:
1. Traverse nums2 from right to left.
2. Maintain a monotonic decreasing stack.
3. For each element:
   - Pop elements smaller than or equal to it.
   - The top of the stack (if any) is the next greater element.
4. Store the result in a hashmap.
5. Build the answer for nums1 using the hashmap.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mpp;

        // Process nums2 to find next greater for each element
        for (int i = nums2.size() - 1; i >= 0; i--) {

            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }

            if (st.empty())
                mpp[nums2[i]] = -1;
            else
                mpp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(mpp[x]);
        }

        return ans;
    }
};

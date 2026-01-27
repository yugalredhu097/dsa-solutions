// Problem: Sliding Window Maximum (LeetCode 239)
// Link: https://leetcode.com/problems/sliding-window-maximum/
// Approach: Monotonic Deque
// Time Complexity: O(n)
// Space Complexity: O(k)

/*
Explanation:
We maintain a deque that stores indices of elements in decreasing order
of their values.

For each index i:
1. Remove indices from the front if they are out of the current window.
2. Remove indices from the back while the current element is greater
   than or equal to the element at those indices.
3. Push the current index.
4. Once the window size reaches k, the front of the deque gives
   the maximum element for the current window.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements out of window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Maintain decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Add result once window is valid
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

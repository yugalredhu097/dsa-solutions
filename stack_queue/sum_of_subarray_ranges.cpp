// Problem: Sum of Subarray Ranges
// Link: https://leetcode.com/problems/sum-of-subarray-ranges/
// Approach: Monotonic Stack (Contribution Technique)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
For every element, we calculate:
- How many subarrays where it is the minimum
- How many subarrays where it is the maximum

Using monotonic stacks:
- PSE: Previous Smaller Element
- NSE: Next Smaller Element
- PGE: Previous Greater Element
- NGE: Next Greater Element

Contribution:
- As minimum: (i - PSE) * (NSE - i) * nums[i]
- As maximum: (i - PGE) * (NGE - i) * nums[i]

Final Answer = Sum(max contributions) - Sum(min contributions)
*/

class Solution {
public:
    void psefunc(vector<int> &pse, vector<int> &nums) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void nsefunc(vector<int> &nse, vector<int> &nums) {
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            nse[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
    }

    void pgefunc(vector<int> &pge, vector<int> &nums) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void ngefunc(vector<int> &nge, vector<int> &nums) {
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            nge[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse(n), nse(n), pge(n), nge(n);
        psefunc(pse, nums);
        nsefunc(nse, nums);
        pgefunc(pge, nums);
        ngefunc(nge, nums);

        long long largest = 0, smallest = 0;

        for (int i = 0; i < n; i++) {
            long long leftSmall = i - pse[i];
            long long rightSmall = nse[i] - i;
            long long leftGreat = i - pge[i];
            long long rightGreat = nge[i] - i;

            largest += leftGreat * rightGreat * nums[i];
            smallest += leftSmall * rightSmall * nums[i];
        }

        return largest - smallest;
    }
};

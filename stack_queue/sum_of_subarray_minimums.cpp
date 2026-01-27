// Problem: Sum of Subarray Minimums
// Link: https://leetcode.com/problems/sum-of-subarray-minimums/
// Approach: Monotonic Stack (Previous & Next Smaller Elements)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
For each element arr[i], we count how many subarrays exist
where arr[i] is the minimum element.

Key Idea:
- Find Previous Smaller Element (PSE)
- Find Next Smaller Element (NSE)

Let:
left  = i - PSE[i]   (number of choices to the left)
right = NSE[i] - i  (number of choices to the right)

Contribution of arr[i]:
arr[i] * left * right

Sum all contributions modulo 1e9+7.
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        vector<int> nse(n), pse(n);
        stack<int> st;

        // Next Smaller Element (strictly smaller or equal on right)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Clear stack
        while (!st.empty()) st.pop();

        // Previous Smaller Element (strictly smaller on left)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long sum = 0;
        int mod = 1e9 + 7;

        // Calculate total contribution
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + (left * right % mod) * arr[i]) % mod;
        }

        return sum;
    }
};

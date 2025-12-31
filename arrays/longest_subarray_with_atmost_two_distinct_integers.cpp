// Problem: Longest Subarray with At Most Two Distinct Integers
// Link: https://www.geeksforgeeks.org/problems/longest-subarray-with-atmost-two-distinct-integers/1
// Approach: Sliding Window with at most 2 distinct elements
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We need to find the length of the longest contiguous subarray
that contains at most two distinct integers.

Approach:
1. Use a sliding window with two pointers (l and r).
2. Maintain a map to store the frequency of elements in the window.
3. Expand the window by moving r.
4. If the window contains more than 2 distinct integers:
   - Shrink the window from the left.
   - Remove elements whose frequency becomes zero.
5. Track the maximum window size.

This ensures an optimal linear-time solution.
*/

class Solution {
  public:
    int totalElements(vector<int>& arr) {

        map<int, int> mpp;
        int l = 0, r = 0;
        int maxlen = 0;
        int n = arr.size();

        while (r < n) {

            mpp[arr[r]]++;

            // Shrink window if more than 2 distinct elements
            while (mpp.size() > 2) {
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0)
                    mpp.erase(arr[l]);
                l++;
            }

            // Update maximum length
            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};

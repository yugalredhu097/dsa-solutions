// Problem: Minimum Length Subarray With Distinct Sum at Least K
// LeetCode: 3795
// Approach: Sliding Window + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We need to find the minimum length subarray such that the
sum of DISTINCT elements in the subarray is at least k.

Approach:
1. Use a sliding window with two pointers (l and r).
2. Maintain a hashmap to track frequencies of elements in the window.
3. Add a number to the sum only when it appears for the first time.
4. While the sum is >= k:
   - Update the minimum window length.
   - Shrink the window from the left.
   - Remove a number from the sum when its frequency becomes zero.
5. If no valid subarray exists, return -1.
*/
class Solution {
public:
    int minLength(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;
        int l = 0, sum = 0;
        int minlen = INT_MAX;
        int n = nums.size();

        for (int r = 0; r < n; r++) {

            if (mpp.find(nums[r]) == mpp.end()) {
                sum += nums[r];
            }
            mpp[nums[r]]++;

            // Try shrinking the window
            while (sum >= k) {

                minlen = min(minlen, r - l + 1);

                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    sum -= nums[l];
                    mpp.erase(nums[l]);
                }
                l++;
            }
        }

        return (minlen == INT_MAX) ? -1 : minlen;
    }
};

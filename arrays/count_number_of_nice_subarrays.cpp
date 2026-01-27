// Problem: Count Number of Nice Subarrays
// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/
// Approach: Sliding Window + At Most Technique
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
A "nice" subarray contains exactly k odd numbers.

Key Idea:
Convert the array into a binary array:
- odd number  -> 1
- even number -> 0

Then the problem becomes:
Count subarrays with sum exactly equal to k.

Using the identity:
Subarrays with sum == k =
    (subarrays with sum <= k) - (subarrays with sum <= k - 1)

Approach:
1. Convert nums into a binary array (odd → 1, even → 0).
2. Use a sliding window helper function to count subarrays
   with sum at most k.
3. Return the difference for exact k.
*/

class Solution {
public:

    // Count subarrays with sum at most k
    int atmost(vector<int>& nums, int k) {

        int l = 0, sum = 0, cnt = 0;
        int n = nums.size();

        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum > k) {
                sum -= nums[l];
                l++;
            }

            cnt += (r - l + 1);
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        // Convert to binary array
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (nums[i] % 2 != 0) ? 1 : 0;
        }

        return atmost(nums, k) - atmost(nums, k - 1);
    }
};

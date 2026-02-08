// Problem: Count Dominant Indices
// Link: https://leetcode.com/problems/count-dominant-indices/
// Approach: Brute-force with suffix sum calculation
// Time Complexity: O(n^2)
// Space Complexity: O(1)

/*
Explanation:
For each index i, we compare nums[i] with the average of
all elements to its right.

An index is considered dominant if:
nums[i] > average of elements from i+1 to n-1.

Approach:
1. For each index i:
   - Compute the sum of elements to the right.
   - Calculate their average.
2. If nums[i] is greater than the average, increment count.
3. Return the final count.
*/

class Solution {
public:
    int sum(int k, vector<int> &nums) {
        int total = 0;
        for (int i = k; i < nums.size(); i++) {
            total += nums[i];
        }
        return total;
    }

    int dominantIndices(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            int avg = sum(i + 1, nums) / (n - i - 1);
            if (nums[i] > avg) cnt++;
        }

        return cnt;
    }
};

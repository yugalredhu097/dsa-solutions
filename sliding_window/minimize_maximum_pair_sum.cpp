// Problem: Minimize Maximum Pair Sum in Array (LeetCode 1877)
// Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// Approach: Sorting + Two Pointers
// Time Complexity: O(n log n)
// Space Complexity: O(1)

/*
Explanation:
To minimize the maximum pair sum:
- Sort the array.
- Pair the smallest element with the largest element.
- Track the maximum sum among all such pairs.
This greedy pairing ensures the maximum pair sum is minimized.
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        int ans = 0;

        while (l < r) {
            ans = max(ans, nums[l] + nums[r]);
            l++;
            r--;
        }
        return ans;
    }
};

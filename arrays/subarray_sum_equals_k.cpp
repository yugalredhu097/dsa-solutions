// Problem: Subarray Sum Equals K
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Approach: Prefix Sum + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We need to count the number of continuous subarrays
whose sum equals k.

Key Idea:
If:
    prefix[j] - prefix[i] = k
then:
    prefix[i] = prefix[j] - k

Approach:
1. Maintain a running prefix sum.
2. Store the frequency of each prefix sum in a map.
3. For each index:
   - Check how many times (prefix - k) has appeared before.
   - Add that count to the answer.
4. Update the map with the current prefix sum.

This allows us to count all valid subarrays in linear time.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        map<int, int> mpp;
        int prefix = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Store current prefix sum
            mpp[prefix]++;

            prefix += nums[i];

            int need = prefix - k;

            if (mpp.find(need) != mpp.end()) {
                cnt += mpp[need];
            }
        }

        return cnt;
    }
};

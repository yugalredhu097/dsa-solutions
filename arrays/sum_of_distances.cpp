// Problem: Sum of Distances
// Link: https://leetcode.com/problems/sum-of-distances/
// Approach: Hash Map + Prefix Sum
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given an array nums.

For each index i:

Find the sum of distances between i
and all other indices j such that:

nums[i] == nums[j]

Distance = |i - j|

------------------------------------------------

Goal:

Return array ans where:

ans[i] = sum of all such distances

------------------------------------------------

Key Idea:

Group equal values together.

Example:

nums = [1,3,1,1,2]

Value 1 occurs at indices:
[0,2,3]

For index 2:

|2-0| + |2-2| + |2-3| = 3

------------------------------------------------

Efficient Formula:

For sorted positions p:

Left contribution:
idx * p[idx] - prefix[idx-1]

Right contribution:
(prefix[last] - prefix[idx])
- (countRight * p[idx])

------------------------------------------------

Steps:

1. Store indices for each value
2. Convert indices to prefix sums
3. For each index:
   compute left + right contribution

------------------------------------------------

Avoids O(n²) brute force.
*/

class Solution {
public:

    vector<long long> distance(vector<int>& nums) {

        unordered_map<int, vector<long long>> mpp;

        // Store indices of each value
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }

        // Convert index lists to prefix sums
        for (auto &it : mpp) {

            vector<long long> prefix(it.second.size());

            long long sum = 0;

            for (int i = 0; i < it.second.size(); i++) {
                sum += it.second[i];
                prefix[i] = sum;
            }

            it.second = prefix;
        }

        vector<long long> ans(nums.size());

        unordered_map<int,int> count;

        for (int i = 0; i < nums.size(); i++) {

            const vector<long long>& v = mpp[nums[i]];

            count[nums[i]]++;

            int idx = count[nums[i]] - 1;

            long long curr = 0;

            // Left side contribution
            if (idx > 0) {
                curr += 1LL * idx * i - v[idx - 1];
            }

            // Right side contribution
            if (idx < v.size() - 1) {
                curr += (v.back() - v[idx])
                      - 1LL * (v.size() - 1 - idx) * i;
            }

            ans[i] = curr;
        }

        return ans;
    }
};
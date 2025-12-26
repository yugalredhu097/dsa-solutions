// Problem: Largest Subarray with 0 Sum
// Link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Approach: Prefix Sum + Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
We need to find the maximum length subarray whose sum is 0.

Key Idea:
If two prefix sums are equal at indices i and j (i < j),
then the subarray between (i+1 to j) has sum 0.

Approach:
1. Compute prefix sum array.
2. If prefix[i] == 0, then subarray [0..i] has sum 0.
3. Store (prefix_sum, index) pairs.
4. Sort the pairs by prefix_sum.
5. For equal prefix sums, the subarray length is:
      max_index - min_index
6. Track the maximum length found.

This method efficiently handles both positive and negative numbers.
*/

class Solution {
  public:
    int maxLength(vector<int>& arr) {

        vector<long long> prefix;
        long long sum = 0;

        // Step 1: Build prefix sum array
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            prefix.push_back(sum);
        }

        // Step 2: Check prefix sum == 0 case
        int maxlen = 0;
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] == 0) {
                maxlen = max(maxlen, i + 1);
            }
        }

        // Step 3: Store prefix sums with indices
        vector<pair<long long, int>> mpp;
        for (int i = 0; i < prefix.size(); i++) {
            mpp.push_back({prefix[i], i});
        }

        // Step 4: Sort by prefix sum
        sort(mpp.begin(), mpp.end());

        // Step 5: Find longest range with same prefix sum
        int i = 0, n = mpp.size();
        while (i < n) {
            int j = i + 1;
            while (j < n && mpp[j].first == mpp[i].first) {
                j++;
            }

            int minIdx = mpp[i].second;
            int maxIdx = mpp[j - 1].second;
            maxlen = max(maxlen, maxIdx - minIdx);

            i = j;
        }

        return maxlen;
    }
};

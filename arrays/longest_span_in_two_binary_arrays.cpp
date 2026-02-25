// Problem: Longest Span in Two Binary Arrays
// Link: https://www.geeksforgeeks.org/problems/longest-span-in-two-binary-arrays/1
// Approach: Prefix Sum + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We are given two binary arrays of equal size.
We need to find the length of the longest span (subarray)
where the sum of elements in both arrays is equal.

Approach:
1. Maintain prefix sums for both arrays.
2. At each index, compute the difference:
      diff = prefix1 - prefix2
3. If diff == 0, the span from 0 to i is valid.
4. If diff has been seen before at index j,
   then the span (j+1 to i) has equal sum.
5. Store the first occurrence of each diff in a hash map.

This reduces the problem to finding the longest subarray
with zero difference in prefix sums.
*/

class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int maxi = 0;
        unordered_map<int, int> mpp;

        int prefix1 = 0, prefix2 = 0;

        for (int i = 0; i < a1.size(); i++) {
            prefix1 += a1[i];
            prefix2 += a2[i];

            int diff = prefix1 - prefix2;

            if (diff == 0) {
                maxi = max(maxi, i + 1);
            }
            else if (mpp.find(diff) != mpp.end()) {
                maxi = max(maxi, i - mpp[diff]);
            }
            else {
                mpp[diff] = i;
            }
        }

        return maxi;
    }
};
// Problem: Rotate Non-Negative Elements (LeetCode 3819)
// Link: https://leetcode.com/problems/rotate-non-negative-elements/
// Approach: Index tracking + Array rotation (reversal method)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
- Extract all non-negative elements and their original indices.
- Rotate only the non-negative elements by k positions using the
  reversal algorithm.
- Place the rotated elements back into their original positions.
- Negative elements remain unchanged.
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> index;
        vector<int> nonneg;

        // Collect non-negative elements and their indices
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                index.push_back(i);
                nonneg.push_back(nums[i]);
            }
        }

        int n = nonneg.size();
        if (n == 0) return nums;

        int k1 = k % n;

        // Rotate using reverse method
        reverse(nonneg.begin(), nonneg.begin() + k1);
        reverse(nonneg.begin() + k1, nonneg.end());
        reverse(nonneg.begin(), nonneg.end());

        // Place rotated elements back
        for (int i = 0; i < n; i++) {
            nums[index[i]] = nonneg[i];
        }

        return nums;
    }
};

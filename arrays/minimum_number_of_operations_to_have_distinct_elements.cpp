// Problem: Minimum Number of Operations to Have Distinct Elements
// Link: https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/
// Approach: Hashing + reverse traversal
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We want to make all elements in the array distinct.
In one operation, we can remove the first three elements of the array.
If fewer than three elements remain, all remaining elements are removed.

Key Idea:
- Traverse the array from the end.
- Use a hash map to track elements we have already seen.
- As soon as a duplicate is found at index i:
  - We need to remove all elements before (and including) that index.
  - Each operation removes 3 elements.
  - Required operations = (i / 3) + 1

Why this works:
- Keeping elements from the end maximizes the chance of uniqueness.
- Removing earlier elements in chunks of 3 minimizes operations.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {

        int minoperations = 0;
        unordered_map<int, int> mpp;

        int i = nums.size() - 1;

        // Traverse from the end
        while (i >= 0) {
            if (mpp.count(nums[i])) {
                minoperations = i / 3 + 1;
                break;
            } else {
                mpp[nums[i]]++;
                i--;
            }
        }

        return minoperations;
    }
};

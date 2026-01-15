// Problem: Longest Consecutive Sequence
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Approach: Hash Set (Optimal)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
We need to find the length of the longest sequence of consecutive
integers in an unsorted array.

Key Idea:
- Insert all numbers into an unordered_set for O(1) lookup.
- A number can start a sequence only if (number - 1) does NOT exist.
- From such a starting point, keep checking consecutive numbers.

This ensures each number is processed only once.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int x : st) {

            // Only start counting if x is the beginning of a sequence
            if (st.count(x - 1))
                continue;

            int current = x;
            int length = 0;

            while (st.count(current)) {
                length++;
                current++;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};

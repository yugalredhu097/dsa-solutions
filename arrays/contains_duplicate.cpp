// Problem: Contains Duplicate
// Link: https://leetcode.com/problems/contains-duplicate/
// Approach: Hash Set
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
Given an integer array, determine if any value appears
at least twice in the array.

Approach:
1. Insert all elements into an unordered_set.
2. If the size of the set is smaller than the array size,
   it means duplicates exist.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }

        return st.size() != nums.size();
    }
};
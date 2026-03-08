// Problem: Find Unique Binary String
// Link: https://leetcode.com/problems/find-unique-binary-string/
// Approach: Backtracking + Hash Set
// Time Complexity: O(2^n * n)
// Space Complexity: O(2^n)

/*
Explanation:
We are given an array of n unique binary strings of length n.
We need to return any binary string of length n that is not present
in the given array.

Approach:
1. Generate all possible binary strings of length n using recursion.
2. Store all input strings in a hash set for quick lookup.
3. Traverse generated strings and return the first string
   that is not present in the set.

Since there are 2^n possible strings and only n are given,
at least one valid answer will always exist.
*/

class Solution {
public:

    void allcombinations(vector<string> &all, string &temp, int n) {
        if (temp.size() == n) {
            all.push_back(temp);
            return;
        }

        temp.push_back('1');
        allcombinations(all, temp, n);
        temp.pop_back();

        temp.push_back('0');
        allcombinations(all, temp, n);
        temp.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums[0].size();

        vector<string> all;
        string temp = "";

        allcombinations(all, temp, n);

        unordered_set<string> st(nums.begin(), nums.end());

        for (string &s : all) {
            if (!st.count(s)) {
                return s;
            }
        }

        return "";
    }
};
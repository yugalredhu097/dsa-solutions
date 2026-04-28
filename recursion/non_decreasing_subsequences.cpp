// Problem: Non-decreasing Subsequences
// Link: https://leetcode.com/problems/non-decreasing-subsequences/
// Approach: Backtracking + Set to handle duplicates
// Time Complexity: O(2^n * n)
// Space Complexity: O(2^n)

/*
Explanation:
We need to find all subsequences of length >= 2 that are non-decreasing.

Approach:
1. Use recursion to generate all possible subsequences.
2. For each subsequence:
   - Check if it is non-decreasing.
   - Length should be at least 2.
3. Use a set to avoid duplicate subsequences.
4. Convert the set into the final answer vector.

Why set?
- Input array may contain duplicates.
- Set ensures uniqueness of subsequences.
*/

class Solution {
public:

    // Check if a sequence is non-decreasing
    bool nondec(vector<int> temp) {
        int i = 0, j = 1;
        int n = temp.size();

        while (j < n) {
            if (temp[i++] > temp[j++])
                return false;
        }
        return true;
    }

    // Recursive function to generate subsequences
    void nondecsubsequences(vector<int>& nums,
                            set<vector<int>>& st,
                            vector<int>& temp,
                            int indx) {

        if (indx == nums.size()) {
            if (temp.size() >= 2 && nondec(temp)) {
                st.insert(temp);
            }
            return;
        }

        // Include current element
        temp.push_back(nums[indx]);
        nondecsubsequences(nums, st, temp, indx + 1);

        // Exclude current element
        temp.pop_back();
        nondecsubsequences(nums, st, temp, indx + 1);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> st;

        nondecsubsequences(nums, st, temp, 0);

        // Convert set to vector
        for (auto& v : st) {
            ans.push_back(v);
        }

        return ans;
    }
};

// Problem: Subset Sums
// Link: https://www.geeksforgeeks.org/problems/subset-sums2234/1
// Approach: Recursion (Pick / Not Pick)
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)

/*
Explanation:
We need to generate the sum of all possible subsets of a given array.

Approach:
1. Use recursion with two choices at each index:
   - Pick the current element → add its value to sum
   - Do not pick the current element → keep sum unchanged
2. When we reach the end of the array, store the current sum.
3. This generates all 2^n subset sums.

This is a classic recursion / backtracking problem.
*/

class Solution {
  public:

    void subsetsums(vector<int>& arr, vector<int>& ans, int sum, int indx) {
        if (indx == arr.size()) {
            ans.push_back(sum);
            return;
        }

        // Pick current element
        subsetsums(arr, ans, sum + arr[indx], indx + 1);

        // Do not pick current element
        subsetsums(arr, ans, sum, indx + 1);
    }

    vector<int> subsetSums(vector<int>& arr) {

        vector<int> ans;
        int sum = 0;

        subsetsums(arr, ans, sum, 0);
        return ans;
    }
};

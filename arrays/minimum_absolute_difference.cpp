// Problem: Minimum Absolute Difference (LeetCode 1200)
// Link: https://leetcode.com/problems/minimum-absolute-difference/
// Approach: Sorting + Linear Scan
// Time Complexity: O(n log n)
// Space Complexity: O(1) (excluding output)

/*
Explanation:
- Sort the array.
- The minimum absolute difference will always occur
  between adjacent elements in the sorted array.
- First, find the minimum difference.
- Then, collect all adjacent pairs whose difference
  equals the minimum.
*/

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        int mini = INT_MAX;
        for (int i = 1; i < n; i++) {
            mini = min(mini, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> ans;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == mini) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};

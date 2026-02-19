// Problem: Missing Element in Range
// Link: https://www.geeksforgeeks.org/problems/missing-element-in-range/1
// Approach: Hash Set
// Time Complexity: O(n + (high - low))
// Space Complexity: O(high - low)

/*
Explanation:
Given an array `arr` and a range [low, high], the task is to find
all elements within this range that are not present in the array.

Approach:
1. Insert all numbers from low to high into a hash set.
2. Traverse the array:
   - If an element lies within the range, remove it from the set.
3. The remaining elements in the set are the missing numbers.
4. Sort the result before returning.

This approach is simple and works efficiently for moderate ranges.
*/

class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<int> ans;
        unordered_set<int> st;

        // Insert the full range
        for (int i = low; i <= high; i++) {
            st.insert(i);
        }

        // Remove elements present in the array
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= low && arr[i] <= high) {
                st.erase(arr[i]);
            }
        }

        // Remaining elements are missing
        for (auto &x : st) {
            ans.push_back(x);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Problem: Third Maximum Number
// Link: https://leetcode.com/problems/third-maximum-number/
// Approach: Use set to remove duplicates + sorting
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
We are given an integer array and need to return the third
distinct maximum number.

Rules:
- If the third distinct maximum exists, return it.
- Otherwise, return the maximum number.

Approach:
1. Insert all elements into an unordered_set to remove duplicates.
2. Convert the set into a vector.
3. Sort the vector in descending order.
4. If the size is less than 3, return the largest element.
5. Otherwise, return the third largest element.
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }

        vector<int> uniqueNums;
        for (int x : st) {
            uniqueNums.push_back(x);
        }

        sort(uniqueNums.rbegin(), uniqueNums.rend());

        if (uniqueNums.size() < 3)
            return uniqueNums[0];

        return uniqueNums[2];
    }
};

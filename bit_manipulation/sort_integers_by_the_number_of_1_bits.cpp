// Problem: Sort Integers by The Number of 1 Bits
// Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Approach: Bit Counting + Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
We need to sort an array based on:
1. Increasing number of set bits (1s) in binary representation.
2. If two numbers have the same number of set bits,
   sort them by their numeric value.

Approach:
1. For each number, count the number of set bits.
2. Store (setBits, value) as a pair.
3. Sort the vector of pairs.
4. Extract the values in sorted order.

This guarantees correct ordering as per the problem rules.
*/

class Solution {
public:
    int onebits(int k) {
        int cnt = 0;
        while (k > 0) {
            cnt += (k & 1);
            k >>= 1;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> temp(n);

        for (int i = 0; i < n; i++) {
            temp[i] = {onebits(arr[i]), arr[i]};
        }

        sort(temp.begin(), temp.end());

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = temp[i].second;
        }

        return ans;
    }
};
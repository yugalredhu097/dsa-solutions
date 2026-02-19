// Problem: Count Binary Substrings
// Link: https://leetcode.com/problems/count-binary-substrings/
// Approach: Grouping consecutive characters
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:
A binary substring is valid if:
- It contains the same number of consecutive 0s and 1s.
- All 0s and all 1s are grouped consecutively.

Approach:
1. Group consecutive identical characters and store their counts.
   Example: "001110" → [2,3,1]
2. For every adjacent pair of groups, add:
   min(group[i], group[i-1]) to the answer.
3. The sum of these values gives the total number of valid substrings.

This works because each adjacent pair contributes substrings
limited by the smaller group size.
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> freq;
        int n = s.size();
        int i = 0;

        // Count lengths of consecutive groups
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            freq.push_back(j - i);
            i = j;
        }

        int cnt = 0;
        // Count valid substrings from adjacent groups
        for (int i = 1; i < freq.size(); i++) {
            cnt += min(freq[i - 1], freq[i]);
        }

        return cnt;
    }
};

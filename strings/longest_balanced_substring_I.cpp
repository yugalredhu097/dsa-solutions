// Problem: Longest Balanced Substring I
// Link: https://leetcode.com/problems/longest-balanced-substring-i/
// Approach: Brute-force with frequency map comparison
// Time Complexity: O(n^2 * k) where k is number of distinct characters
// Space Complexity: O(k)

/*
Explanation:
A substring is considered balanced if all characters present
in it occur the same number of times.

Approach:
1. Try every possible starting index i.
2. Extend the substring to j while maintaining a frequency map.
3. After each extension, check if all frequencies are equal.
4. If balanced, update the maximum length.

This brute-force approach ensures all substrings are evaluated.
*/

class Solution {
public:
    bool isBalanced(unordered_map<int,int> &mpp) {
        int freq = mpp.begin()->second;
        for (auto &a : mpp) {
            if (a.second != freq) return false;
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxi = INT_MIN;

        unordered_map<int,int> mpp;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                if (isBalanced(mpp)) {
                    maxi = max(maxi, j - i + 1);
                }
            }
            mpp.clear();
        }

        return maxi;
    }
};

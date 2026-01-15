// Problem: Maximize Square Hole Area
// Link: https://leetcode.com/problems/maximize-square-hole-area/
// Approach: Find longest consecutive bars in both directions
// Time Complexity: O(n log n + m log m)
// Space Complexity: O(n + m)

/*
Explanation:
We are given horizontal and vertical bars removed from a grid.
A square hole can be formed only by consecutive removed bars.

Steps:
1. Sort both horizontal and vertical bar arrays.
2. Find the longest consecutive sequence in each array.
3. The maximum square side length is:
   min(longest_horizontal + 1, longest_vertical + 1)
4. Return side^2 as the maximum square area.
*/

class Solution {
public:

    void longestConsecutive(vector<int> &res, vector<int> &bars) {
        int i = 0;
        int n = bars.size();
        int maxLen = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && bars[j] == bars[j - 1] + 1) {
                j++;
            }

            if (j - i > maxLen) {
                maxLen = j - i;
                res.clear();
                for (int k = i; k < j; k++) {
                    res.push_back(bars[k]);
                }
            }
            i = j;
        }
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        vector<int> hSeq, vSeq;
        longestConsecutive(hSeq, hBars);
        longestConsecutive(vSeq, vBars);

        int side = min(
            hSeq.back() - hSeq.front() + 2,
            vSeq.back() - vSeq.front() + 2
        );

        return side * side;
    }
};

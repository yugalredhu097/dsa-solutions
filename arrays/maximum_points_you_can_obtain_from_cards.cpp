// Problem: Maximum Points You Can Obtain from Cards
// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Approach: Sliding Window (take from left and right)
// Time Complexity: O(k)
// Space Complexity: O(1)

/*
Explanation:
You are allowed to take exactly k cards from either the beginning
or the end of the array.

Key Idea:
Instead of trying all combinations, we:
1. Take the first k cards from the left as an initial sum.
2. Then, gradually replace cards taken from the left with cards
   taken from the right.
3. Track the maximum sum during this process.

This simulates all valid ways of taking k cards using a sliding window.
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int maxscore = 0;
        int lsum = 0;

        // Sum of first k elements (take all from left)
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        int rsum = 0;
        int n = cardPoints.size();

        int l = k - 1;
        int r = n - 1;

        int sum = lsum + rsum;
        maxscore = sum;

        // Slide window: replace left cards with right cards
        while (r >= n - k) {
            sum -= cardPoints[l];
            l--;
            sum += cardPoints[r];
            r--;
            maxscore = max(maxscore, sum);
        }

        return maxscore;
    }
};

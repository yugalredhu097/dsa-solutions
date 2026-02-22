// Problem: Find the Score Difference in a Game
// Link: https://leetcode.com/problems/find-the-score-difference-in-a-game/
// Approach: Simulation
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
Two players (A and B) play a game by picking numbers from the array
based on specific rules:
- Turns may switch after every 6th move.
- If the number is even, it is added to the current player's score.
- If the number is odd, the turn switches immediately, and the number
  is added to the new player's score.

Approach:
1. Maintain scores for player A and B.
2. Use a flag `a` to track whose turn it is (1 → A, 0 → B).
3. Traverse the array and apply the rules accordingly.
4. Return the difference between A's score and B's score.
*/

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int ascore = 0, bscore = 0;
        int a = 1; // 1 -> Player A, 0 -> Player B

        for (int i = 0; i < nums.size(); i++) {

            // Switch turn after every 6th move
            if ((i + 1) % 6 == 0) {
                a = !a;
            }

            if (nums[i] % 2 == 0) {
                // Even number: add to current player
                if (a == 1) ascore += nums[i];
                else bscore += nums[i];
            } else {
                // Odd number: switch turn, then add
                a = !a;
                if (a == 1) ascore += nums[i];
                else bscore += nums[i];
            }
        }

        return ascore - bscore;
    }
};
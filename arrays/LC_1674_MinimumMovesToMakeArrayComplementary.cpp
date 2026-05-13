// Problem: Minimum Moves to Make Array Complementary
// Platform: LeetCode
// Problem ID: 1674
// Link: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
// Approach: Difference Array + Sweep Line
// Time Complexity: O(n + limit)
// Space Complexity: O(limit)

/*
Explanation:

We are given:
- Array nums
- Integer limit

Goal:
Make every pair:
(nums[i], nums[n-i-1])

have the same sum using minimum moves.

------------------------------------------------

Operation:

In one move:
change any element to value in [1, limit]

------------------------------------------------

Key Observation:

For each pair (a, b):

1. Current target sum:
   target = a + b

2. Minimum possible sum:
   2

3. Maximum possible sum:
   2 * limit

------------------------------------------------

Cost Structure:

For a chosen sum S:

- 0 moves:
    if S == a + b

- 1 move:
    if S lies in:
    [min(a,b)+1 , max(a,b)+limit]

- 2 moves:
    otherwise

------------------------------------------------

Optimization:

Instead of checking every pair for every sum,
use Difference Array.

------------------------------------------------

Range Updates:

Initially:
all sums require 2 moves.

Then:
- Reduce by 1 for valid 1-move range
- Reduce by 1 again at exact target sum

Finally:
Sweep prefix sum to compute total moves.

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minMoves(vector<int>& nums, int limit) {

        vector<int> diff(2 * limit + 2, 0);

        int n = nums.size();

        for(int i = 0; i < n / 2; i++){

            int a = nums[i];
            int b = nums[n - i - 1];

            // Initially assume 2 moves
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // Range requiring only 1 move
            int lower = min(a, b) + 1;
            int upper = max(a, b) + limit;

            diff[lower] -= 1;
            diff[upper + 1] += 1;

            // Exact target requiring 0 moves
            int target = a + b;

            diff[target] -= 1;
            diff[target + 1] += 1;
        }

        int ans = n;
        int current_moves = 0;

        // Sweep line
        for(int i = 2; i <= 2 * limit; i++){

            current_moves += diff[i];

            ans = min(ans, current_moves);
        }

        return ans;
    }
};
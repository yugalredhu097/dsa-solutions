// Problem: Minimum Number of Seconds to Make Mountain Height Zero
// Link: https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/
// Approach: Binary Search on Answer + Mathematical Calculation
// Time Complexity: O(n log answer)
// Space Complexity: O(1)

/*
Explanation:

We are given:
- mountainHeight → total height of the mountain
- workerTimes → time taken by each worker for the first unit

Each worker takes:
t, 2t, 3t, 4t ... seconds for removing layers.

So removing k layers takes:

t * (1 + 2 + 3 + ... + k)
= t * (k * (k + 1) / 2)

Goal:
Find the minimum time required so that workers together
can remove mountainHeight layers.

--------------------------------------------------

Binary Search Idea:

Instead of simulating time, we binary search the answer.

For a given time m:
calculate how many layers each worker can remove.

From:

t * (k * (k + 1) / 2) ≤ m

Solve for k:

k = (-1 + sqrt(1 + 8m/t)) / 2

This gives how many layers a worker can remove in time m.

--------------------------------------------------

Steps:

1. Binary search on time.
2. For each mid time, check if workers can remove
   at least mountainHeight layers.
3. If yes → try smaller time.
4. If no → increase time.

Return the minimum valid time.
*/

class Solution {
public:

    bool ispossible(long long m, int h, vector<int> &t) {

        long long removed = 0;

        for (int i = 0; i < t.size(); i++) {

            removed += (-1 + sqrt(1 + (8LL * m) / t[i])) / 2;

            if (removed >= h)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long s = 0;

        long long maxTime = *max_element(workerTimes.begin(), workerTimes.end());

        long long e = maxTime * 1LL * mountainHeight * (mountainHeight + 1) / 2;

        long long ans = 0;

        while (s <= e) {

            long long mid = s + (e - s) / 2;

            if (ispossible(mid, mountainHeight, workerTimes)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
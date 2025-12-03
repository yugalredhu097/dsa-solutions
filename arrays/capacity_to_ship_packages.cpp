// Problem: Capacity to Ship Packages Within D Days
// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Approach: Binary Search on Answer
// Time Complexity: O(n log(sum(weights)))
// Space Complexity: O(1)

/*
Explanation:
We need to find the minimum ship capacity such that all packages are delivered within D days.

1. The minimum possible capacity is the maximum weight in the array
   (because we must ship at least the heaviest package).

2. The maximum possible capacity is the sum of all weights
   (ship everything in a single day).

3. We apply binary search between this minimum and maximum capacity:
   - For each mid value, we check if we can ship everything within D days.
   - If possible, we reduce the capacity (search left).
   - If not possible, we increase the capacity (search right).

This is a classic binary search on the answer problem.
*/

class Solution {
public:
    // Helper to compute sum of weights
    int sum(vector<int>& weights) {
        int total = 0;
        for (int i = 0; i < weights.size(); i++) {
            total += weights[i];
        }
        return total;
    }

    // Check if we can ship with capacity k within given days
    bool timetaken(vector<int>& weights, int days, int k) {
        int daysreq = 1;
        int loaded = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] + loaded <= k) {
                loaded += weights[i];
            } else {
                daysreq++;

                if (daysreq > days)
                    return false;
                
                loaded = weights[i];
            }
        }
        return true;
    }

    // Main function using binary search
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());
        int e = sum(weights);
        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (timetaken(weights, days, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};

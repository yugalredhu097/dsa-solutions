// Problem: Maximum Capacity Under Budget (LeetCode 3814)
// Link: https://leetcode.com/problems/maximum-capacity-under-budget/
// Approach: Sorting + Prefix Maximum + Binary Search
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/*
Explanation:
Each item has a cost and a capacity.
We want to pick at most two items such that:
- Total cost < budget
- Total capacity is maximized

Steps:
1. Pair each cost with its original index and sort by cost.
2. Build a prefix maximum array of capacities for fast lookup.
3. Case 1: Pick only one item whose cost < budget.
4. Case 2: Pick two items:
   - Fix one item.
   - Binary search the best second item whose cost fits the remaining budget.
   - Use prefix max to get maximum capacity efficiently.
5. Return the maximum capacity found.
*/

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({costs[i], i});
        }

        sort(v.begin(), v.end());

        // Prefix maximum capacity
        vector<int> prefmax(n);
        int maxcap = 0;
        for (int i = 0; i < n; i++) {
            maxcap = max(maxcap, capacity[v[i].second]);
            prefmax[i] = maxcap;
        }

        int ans = 0;

        // Case 1: single item
        for (int i = 0; i < n; i++) {
            if (v[i].first < budget) {
                ans = max(ans, capacity[v[i].second]);
            }
        }

        // Case 2: two items
        for (int i = n - 1; i >= 1; i--) {
            int s = 0, e = i - 1;
            int best = -1;

            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (v[mid].first + v[i].first < budget) {
                    best = mid;
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }

            if (best != -1) {
                ans = max(ans,
                          capacity[v[i].second] + prefmax[best]);
            }
        }

        return ans;
    }
};

// Problem: Closest Equal Element Queries
// Link: https://leetcode.com/problems/closest-equal-element-queries/
// Approach: Hash Map + Binary Search + Circular Distance
// Time Complexity: O(n + q log f)
//   n = nums.size()
//   q = queries.size()
//   f = frequency of queried element
// Space Complexity: O(n)

/*
Explanation:

We are given:
- nums array
- queries containing indices

For each query index q:

Find the minimum circular distance from index q
to another index having the same value nums[q].

------------------------------------------------

Circular Distance:

distance(i, j) = min(|i-j|, n-|i-j|)

------------------------------------------------

Key Idea:

1. Store all indices for each value:
   value -> sorted list of positions

2. For each query:
   - Get list of same-value indices
   - If only one occurrence -> answer = -1

3. Use binary search to locate query index
   inside that index list.

4. Check nearest neighbors:
   - previous occurrence
   - next occurrence

5. Compute circular distances.

------------------------------------------------

Why only neighbors?

Because positions are sorted, closest match
must be adjacent in cyclic order.
*/

class Solution {
public:

    int search(vector<int>& v, int target) {

        int s = 0, e = (int)v.size() - 1;

        while (s <= e) {

            int mid = s + (e - s) / 2;

            if (v[mid] == target)
                return mid;
            else if (v[mid] > target)
                e = mid - 1;
            else
                s = mid + 1;
        }

        return -1;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        unordered_map<int, vector<int>> mpp;

        // Store indices of each value
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }

        vector<int> ans;
        int n = nums.size();

        for (int q : queries) {

            vector<int>& v = mpp[nums[q]];

            // Only one occurrence
            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = search(v, q);

            int next = v[(idx + 1) % v.size()];
            int prev = v[(idx - 1 + v.size()) % v.size()];

            int d1 = abs(q - next);
            d1 = min(d1, n - d1);

            int d2 = abs(q - prev);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};
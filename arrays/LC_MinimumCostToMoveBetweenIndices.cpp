// Problem: Minimum Cost to Move Between Indices
// Platform: LeetCode
// Link: (Add problem link when available)
// Approach: Preprocessing + Greedy Nearest Move + Prefix/Suffix Cost
// Time Complexity: O(n + q)
// Space Complexity: O(n)

/*
Explanation:

We are given:

- Array nums
- Queries [l, r]

We need minimum cost to move from index l to r.

------------------------------------------------

Key Idea:

From any index i, we can:
- Move to adjacent index with cost:
  abs difference OR 1 depending on "closest"

------------------------------------------------

Preprocessing:

1. Build closest[]:
   closest[i] = index (i-1 or i+1) which has minimum difference

2. Build prefix cost array:
   pref[i] = cost to move from 0 → i

3. Build suffix cost array:
   suff[i] = cost to move from n-1 → i

------------------------------------------------

Transition:

If closest[i] points backward:
    moving forward costs abs(nums[i] - nums[i+1])
Else:
    cost = 1

Similarly for backward direction.

------------------------------------------------

Answer Queries:

- If l < r:
    answer = pref[r] - pref[l]

- Else:
    answer = suff[r] - suff[l]

------------------------------------------------

Why this works?

We precompute optimal movement costs so each query
can be answered in O(1).

------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> closest(n);

        // Step 1: Find closest neighbor
        for(int i = 0; i < n; i++){
            if(i == 0) closest[i] = 1;
            else if(i == n - 1) closest[i] = n - 2;
            else{
                if(abs(nums[i] - nums[i-1]) <= abs(nums[i] - nums[i+1]))
                    closest[i] = i - 1;
                else
                    closest[i] = i + 1;
            }
        }

        // Step 2: Build prefix cost
        vector<int> pref(n);
        int cost = 0;

        for(int i = 0; i < n; i++){
            pref[i] = cost;

            if(i == n - 1) break;

            if(closest[i] < i)
                cost += abs(nums[i] - nums[i+1]);
            else
                cost += 1;
        }

        // Step 3: Build suffix cost
        vector<int> suff(n);

        for(int i = n - 1; i >= 0; i--){
            suff[i] = cost;

            if(i == 0) break;

            if(closest[i] > i)
                cost += abs(nums[i] - nums[i-1]);
            else
                cost += 1;
        }

        // Step 4: Answer queries
        vector<int> ans;

        for(auto &q : queries){
            int l = q[0];
            int r = q[1];

            if(l < r){
                ans.push_back(pref[r] - pref[l]);
            } else {
                ans.push_back(suff[r] - suff[l]);
            }
        }

        return ans;
    }
};
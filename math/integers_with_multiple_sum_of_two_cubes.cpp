// Problem: Integers With Multiple Sum of Two Cubes
// Link: https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes/
// Approach: Precompute Cubes + Hashing
// Time Complexity: O(n^(2/3))
// Space Complexity: O(n)

/*
Explanation:

We are given an integer n.

Goal:
Find all integers ≤ n that can be expressed as the sum of two cubes
in at least two different ways.

------------------------------------------------

Key Idea:

1. Generate all cubes ≤ n:
   i³ where i ≤ cbrt(n)

2. Try all pairs (i, j):
   sum = i³ + j³

3. Use a hashmap:
   sum → count of ways to form it

4. If a number can be formed in ≥ 2 ways,
   include it in the result.

------------------------------------------------

Steps:

1. Generate cube list
2. Check all pairs
3. Count occurrences using map
4. Collect results with count ≥ 2
5. Sort and return

------------------------------------------------

Example:

1729 = 1³ + 12³ = 9³ + 10³

So 1729 is included.

------------------------------------------------

This is related to "Taxicab numbers".
*/

class Solution {
public:
    vector<int> findGoodIntegers(int n) {

        vector<int> ans;
        vector<int> cubes;

        int limit = cbrt(n);

        // Generate cubes
        for (int i = 1; i <= limit; i++) {
            cubes.push_back(i * i * i);
        }

        unordered_map<int, int> mpp;

        // Check all pairs
        for (int i = 0; i < cubes.size(); i++) {
            for (int j = i + 1; j < cubes.size(); j++) {

                int sum = cubes[i] + cubes[j];

                if (sum <= n)
                    mpp[sum]++;
            }
        }

        // Collect answers
        for (auto &it : mpp) {
            if (it.second >= 2) {
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
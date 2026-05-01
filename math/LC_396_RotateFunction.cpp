// Problem: Rotate Function
// Platform: LeetCode
// Problem ID: 396
// Link: https://leetcode.com/problems/rotate-function/
// Approach: Mathematical Optimization (Prefix Sum Transformation)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:

We are given an array nums.

Define rotation function:

F(k) = sum(i * nums[(i + k) % n])

We need to find maximum value of F(k).

------------------------------------------------

Brute Force:

Compute F(k) for all k → O(n^2)

Too slow.

------------------------------------------------

Key Optimization:

Let:
F(0) = sum(i * nums[i])
total = sum(nums[i])

Then:

F(k) = F(k-1) + total - n * nums[n-k]

------------------------------------------------

Why?

Each rotation shifts elements:
- Every element contributes +1 more
- Except last element which moves to front

So we adjust using formula.

------------------------------------------------

Steps:

1. Compute:
   - total sum
   - F(0)

2. Iterate backwards:
   Use formula to compute next F(k)

3. Track maximum

------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long total = 0;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            total += nums[i];
            sum += 1LL * nums[i] * i;
        }

        long long maxi = sum;

        for(int i = n - 1; i > 0; i--){
            sum = sum + total - 1LL * n * nums[i];
            maxi = max(maxi, sum);
        }

        return (int)maxi;
    }
};
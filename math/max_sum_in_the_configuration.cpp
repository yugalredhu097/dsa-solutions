// Problem: Max Sum in the Configuration
// Link: https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1
// Approach: Mathematical Observation with Array Rotations
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
Given an array arr[] of size n, we need to find the maximum value of:
sum(i * arr[i]) for all possible rotations of the array.

Approach:
1. Compute:
   - total sum of the array
   - value of sum(i * arr[i]) for the initial configuration
2. Use the relation to compute the next rotation value efficiently:
   R(i) = R(i-1) + totalSum - n * arr[n - i]
3. Track the maximum value among all rotations.

This avoids recomputing the sum from scratch for every rotation.
*/

class Solution {
public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();

        int total = 0;
        int currSum = 0;

        // Initial configuration
        for (int i = 0; i < n; i++) {
            total += arr[i];
            currSum += i * arr[i];
        }

        int maxSum = currSum;

        // Compute values for remaining rotations
        for (int i = n - 1; i > 0; i--) {
            currSum = currSum + total - n * arr[i];
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};

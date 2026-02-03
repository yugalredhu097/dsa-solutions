// Problem: Maximum Circular Subarray Sum
// Link: https://www.geeksforgeeks.org/problems/maximum-circular-subarray-sum-1587115620/1
// Approach: Kadane’s Algorithm (Normal + Inverted)
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
The maximum circular subarray sum can be of two types:
1. Non-circular (normal maximum subarray sum)
2. Circular (total sum - minimum subarray sum)

Approach:
1. Use Kadane’s algorithm to find the maximum subarray sum (nonwrap).
2. Use a modified Kadane’s algorithm to find the minimum subarray sum (minsum).
3. Compute the total sum of the array.
4. The circular sum is total - minsum.
5. If all elements are negative, return the non-circular result.

This ensures the maximum possible subarray sum in circular manner.
*/

class Solution {
public:
    int maxCircularSum(vector<int> &arr) {
        long long minsum = LLONG_MAX;
        long long nonwrap = LLONG_MIN;
        long long sum1 = 0, sum2 = 0, total = 0;

        for (int x : arr) {
            total += x;

            // Kadane for maximum subarray sum
            sum1 += x;
            nonwrap = max(nonwrap, sum1);
            if (sum1 < 0) sum1 = 0;

            // Kadane for minimum subarray sum
            sum2 += x;
            minsum = min(minsum, sum2);
            if (sum2 > 0) sum2 = 0;
        }

        // If all elements are negative
        if (nonwrap < 0) return nonwrap;

        return max(nonwrap, total - minsum);
    }
};

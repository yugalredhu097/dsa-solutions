// Problem: Maximum XOR Subarray of Size K
// Link: https://www.geeksforgeeks.org/problems/maximum-xor-subarray-of-size-k/1
// Approach: Sliding Window + XOR
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:
We are given an array and an integer k.
The task is to find the maximum XOR value among all
subarrays of size exactly k.

Approach:
1. Compute XOR of the first k elements.
2. Use a sliding window:
   - Remove the leftmost element using XOR.
   - Add the next element using XOR.
3. Update the maximum XOR value at each step.

This works because XOR allows efficient add/remove
operations in constant time.
*/

class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int maxi = 0;
        int XOR = 0;

        // Compute XOR of first window
        for (int i = 0; i < k; i++) {
            XOR ^= arr[i];
        }

        maxi = max(maxi, XOR);

        int l = 0, r = k - 1;
        int n = arr.size();

        while (r < n) {
            XOR ^= arr[l];
            l++;
            r++;

            if (r >= n) break;

            XOR ^= arr[r];
            maxi = max(maxi, XOR);
        }

        return maxi;
    }
};
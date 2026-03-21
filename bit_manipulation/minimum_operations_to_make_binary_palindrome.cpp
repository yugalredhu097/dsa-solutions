// Problem: Minimum Operations to Make Binary Palindrome
// Link: https://leetcode.com/problems/minimum-operations-to-make-binary-palindrome/description/
// Approach: Precompute all binary palindromes + use binary search
// Time Complexity: O(N log M)  where M = number of palindromes
// Space Complexity: O(M)

/*
Explanation:

We need to transform each integer in the array into a number whose binary
representation is a palindrome. The cost is the minimum number of 
increment/decrement operations required.

Example:
13 -> binary: 1101 (not palindrome)
Closest palindromes:
    15 -> 1111 (cost 2)
    9  -> 1001 (cost 4)
Answer = 2

Strategy:

1. Reflection function:
   Reverse bits of a number to check if it is a binary palindrome.

2. Precompute palindromes:
   Generate all binary palindrome numbers from 1 to 6000.
   (6000 is enough for constraints based on problem statement)

3. For each element:
   - Use lower_bound to find closest palindrome ≥ x
   - Check previous palindrome < x
   - Take min(|x - left|, |right - x|)

This ensures optimal operations for each value.
*/

class Solution {
public:

    // Reverse bits until highest set bit
    int reflection(int n) {
        int result = 0;
        while (n > 0) {
            int bit = n & 1;
            result = (result << 1) | bit;
            n >>= 1;
        }
        return result;
    }

    // Check if number is binary palindrome
    bool ispalindrome(int n) {
        return reflection(n) == n;
    }

    vector<int> minOperations(vector<int>& nums) {

        // Step 1: Precompute all palindromic binary numbers up to 6000
        vector<int> pali;
        for (int i = 1; i <= 6000; i++) {
            if (ispalindrome(i))
                pali.push_back(i);
        }

        vector<int> ans;

        // Step 2: For each number, find closest binary palindrome
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(pali.begin(), pali.end(), nums[i]);
            int idx = it - pali.begin();

            // If exact match, cost = 0
            if (idx < pali.size() && pali[idx] == nums[i]) {
                ans.push_back(0);
            }
            else {
                int cost1 = INT_MAX, cost2 = INT_MAX;

                if (idx < pali.size())
                    cost1 = abs(pali[idx] - nums[i]);       // nearest palindrome on right

                if (idx > 0)
                    cost2 = abs(nums[i] - pali[idx - 1]);   // nearest palindrome on left

                ans.push_back(min(cost1, cost2));
            }
        }

        return ans;
    }
};

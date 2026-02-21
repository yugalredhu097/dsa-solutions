// Problem: Prime Number of Set Bits in Binary Representation
// Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Approach: Bit Counting + Sieve of Eratosthenes
// Time Complexity: O((right - left + 1) * log n)
// Space Complexity: O(1)

/*
Explanation:
For every number in the range [left, right]:
1. Count the number of set bits (1s) in its binary representation.
2. Check if the count of set bits is a prime number.
3. If yes, include it in the result.

Approach:
- Use a helper function to count set bits.
- Precompute prime numbers up to 32 using the Sieve of Eratosthenes
  (since max bits in an integer ≤ 32).
- Iterate through the range and count valid numbers.
*/

class Solution {
public:
    int bitsets(int k) {
        int cnt = 0;
        while (k > 0) {
            cnt += (k & 1);
            k >>= 1;
        }
        return cnt;
    }

    int countPrimeSetBits(int left, int right) {
        int cnt = 0;

        // Sieve to mark prime numbers up to 32
        vector<int> prime(33, 1);
        prime[0] = 0;
        prime[1] = 0;

        for (int i = 2; i * i <= 32; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= 32; j += i) {
                    prime[j] = 0;
                }
            }
        }

        // Count numbers with prime set bits
        for (int i = left; i <= right; i++) {
            int setBits = bitsets(i);
            if (prime[setBits]) cnt++;
        }

        return cnt;
    }
};
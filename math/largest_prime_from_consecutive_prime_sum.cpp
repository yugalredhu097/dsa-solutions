// Problem: 3770. Largest Prime from Consecutive Prime Sum
// Link: https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum/
// Approach: Sieve of Eratosthenes + consecutive prime prefix sum
// Time Complexity: O(n log log n) for sieve + O(n)
// Space Complexity: O(n)

/*
Explanation:
We want the largest prime X such that:
- X <= n
- X can be formed as a sum of consecutive prime numbers starting from 2

For example:
n = 30
Consecutive primes: 2, 3, 5, 7, 11 ...
Sums: 2, 5, 10, 17, 28, 39 ...
Prime sums <= 30: 2, 5, 17  → answer = 17

Steps:
1. Use sieve to generate all primes up to n.
2. Keep a running sum of primes (2 + 3 + 5 + 7 + ...)
3. At each step:
   - If sum <= n AND sum is prime → update result
4. Stop when sum > n.
*/

class Solution {
public:
    int largestPrime(int n) {
        if (n < 2) return 0;

        // STEP 1: Sieve of Eratosthenes
        vector<int> prime(n + 1, 1);
        prime[0] = prime[1] = 0;

        for (int i = 2; i * i <= n; i++) {
            if (prime[i] == 1) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }

        // STEP 2: Consecutive prime sum
        long long sum = 0;
        int maxi = 0;

        for (int i = 2; i <= n; i++) {
            if (prime[i] == 1) {
                sum += i;

                // Check if sum is a prime <= n
                if (sum <= n && prime[sum] == 1) {
                    maxi = sum;
                }

                // Stop once sum exceeds n
                if (sum > n) break;
            }
        }

        return maxi;
    }
};

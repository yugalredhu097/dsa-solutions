// Problem: Count Good Numbers
// Link: https://leetcode.com/problems/count-good-numbers/
// Approach: Fast Exponentiation (Binary Exponentiation)
// Time Complexity: O(log n)
// Space Complexity: O(log n) (recursive stack)

/*
Explanation:
A number is considered "good" if:
- Digits at even indices can be one of {0, 2, 4, 6, 8} → 5 choices
- Digits at odd indices can be one of {2, 3, 5, 7} → 4 choices

Given length n:
- Number of even positions = (n + 1) / 2
- Number of odd positions  = n / 2

Total good numbers:
= (5 ^ evenPositions) * (4 ^ oddPositions) mod (1e9 + 7)

Approach:
1. Count even and odd positions.
2. Use fast exponentiation to compute powers efficiently.
3. Multiply both results under modulo.
*/

class Solution {
public:
    long long power(long long x, long long N, long long MOD) {
        if (N == 0) return 1;

        long long half = power(x, N / 2, MOD);
        long long res = (half * half) % MOD;

        if (N % 2 == 1) {
            res = (res * x) % MOD;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long MOD = 1e9 + 7;

        long long even = (n + 1) / 2;
        long long odd  = n / 2;

        long long ans = (power(5, even, MOD) * power(4, odd, MOD)) % MOD;
        return (int)ans;
    }
};

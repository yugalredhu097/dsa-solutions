// Problem: Complete Prime
// Platform: LeetCode (or Custom Prime Problem)
// Approach: Prefix & suffix prime validation
// Time Complexity: O(n * sqrt(num))
// Space Complexity: O(1)

/*
Definition:
A number is called a "Complete Prime" if:
1. All prefixes of the number (from left) are prime.
2. All suffixes of the number (from right) are prime.

Example:
num = 233
Prefixes: 2, 23, 233  → all prime
Suffixes: 233, 33, 3  → 33 is not prime → false

Steps:
1. Convert number to string.
2. Check every prefix (0 to i).
3. Check every suffix (i to end).
4. Use a primality function for checks.

We directly check primality using sqrt(n) divisor check because
the number length is small and operations are fast enough.
*/

class Solution {
public:

    // Check if a number is prime
    bool isprime(long long n) {
        if (n < 2) return false;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        // Check all prefixes
        for (int i = 1; i <= n; i++) {
            long long prefix = stoll(s.substr(0, i));
            if (!isprime(prefix))
                return false;
        }

        // Check all suffixes
        for (int i = 0; i < n; i++) {
            long long suffix = stoll(s.substr(i, n - i));
            if (!isprime(suffix))
                return false;
        }

        return true;
    }
};

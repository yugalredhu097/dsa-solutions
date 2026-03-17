// Problem: Simons and Cakes for Success
// Link: https://codeforces.com/problemset/problem/2205/B
// Approach: Prime Factorization + Product of Distinct Prime Factors
// Time Complexity: O(√n)
// Space Complexity: O(k) where k is the number of distinct prime factors

/*
Explanation:

For each test case we are given an integer n.

Goal:
Compute the product of all DISTINCT prime factors of n.

Steps:

1. Extract factor 2 while n is even.
2. Iterate through odd numbers from 3 to √n and
   divide n while it is divisible by that number.
3. Store each distinct factor in a set.
4. If the remaining n > 2, it is also a prime factor.
5. Multiply all unique factors to obtain the answer.

Example:

n = 12

Prime factorization:
12 = 2 × 2 × 3

Distinct prime factors:
{2, 3}

Answer:
2 × 3 = 6
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        unordered_set<int> s;
        int ans = 1;

        // Handle factor 2
        while (n % 2 == 0) {
            s.insert(2);
            n /= 2;
        }

        // Handle odd factors
        for (int i = 3; i <= sqrt(n); i += 2) {
            while (n % i == 0) {
                s.insert(i);
                n /= i;
            }
        }

        // If remaining n is prime
        if (n > 2) {
            s.insert(n);
        }

        // Multiply distinct factors
        for (int factor : s) {
            ans *= factor;
        }

        cout << ans << endl;
    }
}
// Problem: Absolute Cinema
// Link: https://codeforces.com/problemset/problem/2195/D
// Approach: Construct Original Array using Difference Relations
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given array a of size n.

Goal:
Reconstruct array ans using mathematical relationships
derived from adjacent values.

------------------------------------------------

Key Observation:

For middle indices:

ans[i] can be computed using:

((a[i-1] - a[i]) - (a[i] - a[i+1])) / 2

This reconstructs internal values.

------------------------------------------------

Then:

Use accumulated contribution of middle elements
to determine:

ans[0]
ans[n-1]

------------------------------------------------

Steps:

1. Compute ans[i] for 1 <= i <= n-2

2. Calculate contribution sums:
   - first
   - last

3. Derive:
   ans[0]
   ans[n-1]

4. Print final array

------------------------------------------------

This is a constructive math problem using equations.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> ans(n, 0);

        // Compute middle values
        for (int i = 1; i < n - 1; i++) {
            ans[i] = ((a[i - 1] - a[i]) - (a[i] - a[i + 1])) / 2;
        }

        long long first = 0;
        long long last = 0;

        for (int i = 1; i < n - 1; i++) {
            first += ans[i] * (n - i - 1);
            last += ans[i] * i;
        }

        // Compute boundary values
        ans[0] = (a[n - 1] - first) / (n - 1);
        ans[n - 1] = (a[0] - last) / (n - 1);

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
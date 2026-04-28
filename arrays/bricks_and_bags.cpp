// Problem: Bricks and Bags
// Link: https://codeforces.com/contest/1740/problem/C
// Approach: Sorting + Greedy Observation
// Time Complexity: O(n log n)
// Space Complexity: O(1) (excluding input array)

/*
Explanation:

We are given n brick weights.

Need to maximize expression formed by choosing
3 bricks and arranging them optimally.

After sorting:

b[0] <= b[1] <= ... <= b[n-1]

------------------------------------------------

Key Observation:

Maximum answer comes from one of two patterns:

1. Use two smallest + largest

   b[n-1] + b[i+1] - 2*b[i]

2. Use smallest + two largest

   2*b[i] - b[i-1] - b[0]

Try all valid i.

------------------------------------------------

Why sorting?

Sorting lets us test extreme values efficiently.

------------------------------------------------

Steps:

1. Sort array
2. Check first pattern
3. Check second pattern
4. Return maximum
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<long long> bricks(n);

        for (int i = 0; i < n; i++) {
            cin >> bricks[i];
        }

        sort(bricks.begin(), bricks.end());

        long long ans = 0;

        // Pattern 1
        for (int i = 0; i < n - 2; i++) {
            ans = max(ans,
                      bricks[n - 1] + bricks[i + 1] - 2 * bricks[i]);
        }

        // Pattern 2
        for (int i = 2; i < n; i++) {
            ans = max(ans,
                      2 * bricks[i] - bricks[i - 1] - bricks[0]);
        }

        cout << ans << endl;
    }

    return 0;
}
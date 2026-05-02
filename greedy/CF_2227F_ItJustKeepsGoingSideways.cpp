// Problem: It Just Keeps Going Sideways
// Platform: Codeforces
// Problem ID: 2227F
// Link: https://codeforces.com/contest/2227/problem/F
// Approach: Frequency Counting + Suffix Aggregation + Greedy Contribution
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given an array of size n.

We analyze contribution changes using frequency
and suffix-based counting.

------------------------------------------------

Key Idea:

1. Count frequency of each value:
   cnt[x] = occurrences of x

2. Build suffix array:
   have[i] = number of elements >= i

------------------------------------------------

Initial Contribution:

init = sum(i * v[i])

------------------------------------------------

Target Contribution:

We compute an optimized contribution:

aft += have[i] * (2*n - have[i] + 1) / 2

This represents placing larger values optimally.

------------------------------------------------

Difference:

cur = aft - init

------------------------------------------------

Optimization:

We try to maximize additional gain:

mx = max(i - n + have[v[i]] - 1)

------------------------------------------------

Final Answer:

cur + mx

------------------------------------------------

Steps:

1. Count frequencies
2. Build suffix counts
3. Compute initial and target contributions
4. Find maximum adjustment
5. Output final result

------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> v(n + 1), cnt(n + 1);

        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            cnt[v[i]]++;
        }

        // Build suffix count
        vector<int> have(n + 1);
        have[n] = cnt[n];

        for(int i = n - 1; i >= 1; i--) {
            have[i] = have[i + 1] + cnt[i];
        }

        // Compute initial and target contribution
        int init = 0, aft = 0;

        for(int i = 1; i <= n; i++) {
            init += i * v[i];
            aft += have[i] * (2 * n - have[i] + 1) / 2;
        }

        int cur = aft - init;

        // Find maximum gain
        int mx = 0;

        for(int i = 1; i <= n; i++) {
            mx = max(mx, i - n + have[v[i]] - 1);
        }

        cout << cur + mx << endl;
    }

    return 0;
}
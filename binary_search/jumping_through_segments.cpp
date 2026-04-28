// Problem: Jumping Through Segments
// Link: https://codeforces.com/problemset/problem/1907/D
// Approach: Binary Search on Answer + Greedy Reachable Range
// Time Complexity: O(n log R)
//   R = max coordinate
// Space Complexity: O(1)

/*
Explanation:

We are given n segments:

[l1, r1], [l2, r2], ... [ln, rn]

Start from position 0.

At each step, we can move at most k distance
before landing inside the next segment.

Goal:
Find the minimum k such that all segments
can be visited in order.

------------------------------------------------

Key Idea:

Binary Search on k.

If a certain k works,
then any larger k also works.

So answer is monotonic.

------------------------------------------------

Check(k):

Maintain reachable range [st, end]
after processing each segment.

Initially:
[0, 0]

For every segment [l, r]:

Expand current reachable range by k:
[st-k, end+k]

Intersect with [l, r]

If intersection is empty:
Impossible.

Else update reachable range.

------------------------------------------------

If all segments processed:
k is possible.

------------------------------------------------

Then binary search minimum valid k.
*/

#include <bits/stdc++.h>
using namespace std;

bool ispossible(long long k, vector<pair<long long,long long>> &seg) {

    long long st = 0, en = 0;

    for (auto &p : seg) {

        long long l = p.first;
        long long r = p.second;

        // Expand reachable range
        long long newL = st - k;
        long long newR = en + k;

        // Intersect with current segment
        st = max(newL, l);
        en = min(newR, r);

        if (st > en)
            return false;
    }

    return true;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<pair<long long,long long>> seg(n);

        long long low = 0;
        long long high = 0;

        for (int i = 0; i < n; i++) {
            cin >> seg[i].first >> seg[i].second;
            high = max(high, seg[i].second);
        }

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (ispossible(mid, seg)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
// Problem: Catching the Krug
// Link: https://codeforces.com/contest/2152/problem/B
// Approach: Case Analysis / Geometry on Grid
// Time Complexity: O(1) per test case
// Space Complexity: O(1)

/*
Explanation:

We are given:

- Grid size n x n
- Krug position (rk, ck)
- Destination position (rd, cd)

Goal:
Find minimum required time / moves
based on relative row and column positions.

------------------------------------------------

Observation:

Only relative placement matters:

1. rk > rd
2. rk == rd
3. rk < rd

Inside each case:
compare columns ck and cd.

Then compute answer using nearest border
or max distance depending on direction.

------------------------------------------------

This becomes direct casework.

------------------------------------------------

Since only comparisons are used:
O(1) per test case.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        long long n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;

        long long ans;

        if (rk > rd) {

            if (ck > cd) {
                ans = max(n - rd, n - cd);
            }
            else if (ck == cd) {
                ans = n - rd;
            }
            else {
                ans = max(n - rd, cd);
            }
        }
        else if (rk == rd) {

            if (ck > cd) {
                ans = n - cd;
            }
            else {
                ans = cd;
            }
        }
        else {

            if (ck > cd) {
                ans = max(rd, n - cd);
            }
            else if (ck == cd) {
                ans = rd;
            }
            else {
                ans = max(rd, cd);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
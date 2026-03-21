// Problem: New Year Cake
// Link: https://codeforces.com/contest/2182/problem/B
// Approach: Simulation + Greedy Pattern
// Time Complexity: O(log n)
// Space Complexity: O(1)

/*
Explanation:

We are given two integers:
a → number of white pieces
b → number of black pieces

We simulate two scenarios:
1. Start with white
2. Start with black

------------------------------------------------

Pattern:

The pieces are used in increasing powers of 4:

Case 1 (start with white):
white → 1, 4, 16, ...
black → 2, 8, 32, ...

Case 2 (start with black):
white → 2, 8, 32, ...
black → 1, 4, 16, ...

------------------------------------------------

Steps:

1. Simulate how many turns we can take for each color.
2. Count valid operations until resources run out.
3. Use conditions to compute maximum possible moves.
4. Take maximum of both starting cases.

------------------------------------------------

Key Insight:

We try both starting configurations and choose
the one that gives the maximum result.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while (t--) {

        int a, b;
        cin >> a >> b;

        // Case 1: Start with white
        int t1 = a, t2 = b;
        int ans1 = 0, ans2 = 0;

        int use = 1;

        while (t1 > 0) {
            t1 -= use;
            if (t1 < 0) break;
            ans1++;
            use *= 4;
        }

        use = 2;

        while (t2 > 0) {
            t2 -= use;
            if (t2 < 0) break;
            ans2++;
            use *= 4;
        }

        int firstcase = 0;

        if (ans1 == ans2 || ans1 == ans2 + 1)
            firstcase = ans1 + ans2;
        else if (ans1 > ans2 + 1)
            firstcase = ans2 * 2 + 1;
        else if (ans2 > ans1)
            firstcase = ans1 * 2;

        // Case 2: Start with black
        t1 = a;
        t2 = b;
        ans1 = 0;
        ans2 = 0;

        use = 2;

        while (t1 > 0) {
            t1 -= use;
            if (t1 < 0) break;
            ans1++;
            use *= 4;
        }

        use = 1;

        while (t2 > 0) {
            t2 -= use;
            if (t2 < 0) break;
            ans2++;
            use *= 4;
        }

        int secondcase = 0;

        if (ans1 == ans2 || ans2 == ans1 + 1)
            secondcase = ans1 + ans2;
        else if (ans2 > ans1 + 1)
            secondcase = ans1 * 2 + 1;
        else if (ans1 > ans2)
            secondcase = ans2 * 2;

        cout << max(firstcase, secondcase) << endl;
    }
}
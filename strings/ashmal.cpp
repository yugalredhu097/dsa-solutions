// Problem: Ashmal
// Link: https://codeforces.com/contest/2180/problem/B
// Approach: Greedy String Concatenation
// Time Complexity: O(n * k) where k = avg string length
// Space Complexity: O(total length of strings)

/*
Explanation:

We are given n strings.

Goal:
Construct the lexicographically smallest possible string
by concatenating all strings in an optimal order.

------------------------------------------------

Key Idea:

For two strings A and B:
- Compare A + B and B + A
- Choose the order that gives smaller result

------------------------------------------------

Approach:

1. Initialize ans as empty.
2. Iterate through all strings:
   - If ans is empty → assign current string
   - Else:
       If s[i] + ans < ans + s[i]
           place s[i] before ans
       Else
           place s[i] after ans

------------------------------------------------

This greedy strategy ensures minimal lexicographical result.

------------------------------------------------

Note:

This is similar to "smallest number formed by concatenation"
type problems.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<string> s(n);

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        string ans = "";

        for (int i = 0; i < n; i++) {

            if (ans.empty()) {
                ans = s[i];
            }
            else {

                if (s[i] + ans < ans + s[i])
                    ans = s[i] + ans;
                else
                    ans = ans + s[i];
            }
        }

        cout << ans << endl;
    }
}
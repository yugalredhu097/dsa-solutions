// Problem: Yes or Yes
// Link: https://codeforces.com/problemset/problem/2178/A
// Approach: Simple Counting
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:

We are given a string s.

Goal:
Determine if the string contains at most one 'Y'.

------------------------------------------------

Approach:

1. Count the number of occurrences of 'Y' in the string.
2. If count ≤ 1 → print "YES"
3. Otherwise → print "NO"

------------------------------------------------

Example:

s = "YES" → count of 'Y' = 1 → YES
s = "YYY" → count of 'Y' = 3 → NO
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'Y')
                cnt++;
        }

        if (cnt <= 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
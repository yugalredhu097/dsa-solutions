// Problem: Your Name
// Link: https://codeforces.com/problemset/problem/2167/B
// Approach: Frequency Counting using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(1) (at most 26 characters)

/*
Explanation:

We are given two strings s and t of length n.

Goal:
Check if both strings contain the same frequency of characters.

------------------------------------------------

Key Idea:

If two strings have identical character frequencies,
then they can be considered equivalent under rearrangement.

------------------------------------------------

Steps:

1. Count frequency of each character in string s.
2. Count frequency of each character in string t.
3. Compare both frequency maps.
4. If equal → print "YES"
   else → print "NO"

------------------------------------------------

Example:

s = "abc"
t = "bca"

Both have:
a → 1
b → 1
c → 1

So output → YES
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while (t--){

        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        unordered_map<char, int> m1, m2;

        for (int i = 0; i < n; i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }

        if (m1 == m2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
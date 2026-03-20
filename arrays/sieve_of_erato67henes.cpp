// Problem: Sieve of Erato67henes
// Link: https://codeforces.com/contest/2195/problem/A
// Approach: Set Lookup / Simple Conditions
// Time Complexity: O(n) per test case
// Space Complexity: O(n)

/*
Explanation:

We are given n numbers.

Goal:
Determine if certain values exist in the array.

Key Idea:

We store all elements in an unordered_set for O(1) lookup.

Condition:
- If 67 exists → answer is YES
- Otherwise → NO

(The condition (st.count(1) && st.count(67)) || st.count(67)
simplifies to just checking if 67 exists.)

------------------------------------------------

Steps:

1. Read input elements.
2. Insert into a set.
3. Check if 67 is present.
4. Print result accordingly.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        unordered_set<int> st;

        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            st.insert(a);
        }

        if (st.count(67))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
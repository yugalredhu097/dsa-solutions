// Problem: A and B
// Link: https://codeforces.com/contest/2149/problem/D
// Approach: Greedy + Median Positioning
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given a string consisting of 'a' and 'b'.

Goal:
Minimize the number of moves required to group all
characters of one type together.

------------------------------------------------

Key Idea:

To minimize movement, we align all occurrences of a character
around its median position.

Why median?
→ It minimizes total absolute distance.

------------------------------------------------

Steps:

1. Store indices of all 'a' → vector a
2. Store indices of all 'b' → vector b

3. For 'a':
   - Choose median index
   - Move all other 'a' elements towards it
   - Adjust for already occupied positions

4. Repeat same for 'b'

5. Return minimum of both results

------------------------------------------------

Distance formula:

We subtract overlaps because elements are shifted into
continuous positions.

------------------------------------------------

This is a classic "minimum moves to group elements"
problem using median optimization.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s(n, '0');

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        long long min1 = 0, min2 = 0;

        vector<int> a, b;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                a.push_back(i);
            else
                b.push_back(i);
        }

        // For 'a'
        int mida = a.size() / 2;

        for (int i = 0; i < mida; i++) {
            min1 += a[mida] - a[i] - 1 - (mida - i - 1);
        }

        for (int i = a.size() - 1; i > mida; i--) {
            min1 += a[i] - a[mida] - 1 - (i - mida - 1);
        }

        // For 'b'
        int midb = b.size() / 2;

        for (int i = 0; i < midb; i++) {
            min2 += b[midb] - b[i] - 1 - (midb - i - 1);
        }

        for (int i = b.size() - 1; i > midb; i--) {
            min2 += b[i] - b[midb] - 1 - (i - midb - 1);
        }

        cout << min(min1, min2) << endl;
    }
}
// Problem: Maximum Prefix Sum
// Platform: Codeforces
// Link: https://codeforces.com/contest/2231/problem/D
// Approach: Prefix Constraints + Greedy Reconstruction
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given:

- String s
- Arrays a and c

Goal:
Construct a valid array satisfying
prefix maximum constraints.

------------------------------------------------

Key Idea:

Let:
b[i] = prefix sum till index i

Then:
c[i] represents maximum allowed prefix value.

------------------------------------------------

Observations:

1. Prefix maximums can never decrease
   → c[i] >= c[i-1]

2. If c[i] > c[i-1]:
   → current prefix must become exactly c[i]

3. If s[i] == '1':
   → current value is fixed

------------------------------------------------

Algorithm:

1. Backward pass:
   Compute maximum valid upper bounds
   for each prefix sum.

2. Forward pass:
   Reconstruct valid prefix sums.

3. Recover original array:
   a[i] = b[i] - b[i-1]

------------------------------------------------

If constraints fail at any step:
→ print NO

Else:
→ print reconstructed array

------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;
    
    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<long long> c(n);

    for (int i = 0; i < n; i++)
        cin >> c[i];
    
    // Prefix maximums cannot decrease
    for (int i = 1; i < n; i++) {

        if (c[i] < c[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    
    // up_b[i] = maximum allowed prefix sum
    vector<long long> up_b(n);

    up_b[n - 1] = c[n - 1];
    
    // Backward pass
    for (int i = n - 1; i > 0; i--) {

        long long max_allowed_prev = c[i - 1];
        
        if (s[i] == '1') {

            up_b[i] =
                min(up_b[i], c[i - 1] + a[i]);
        }
        
        if (c[i] > c[i - 1]) {

            if (up_b[i] < c[i]) {
                cout << "NO\n";
                return;
            }

            up_b[i] = c[i];

            max_allowed_prev = c[i] - a[i]; 
        }
        
        // Propagate constraints backward
        if (s[i] == '1') {
            up_b[i - 1] = up_b[i] - a[i];
        }
        else {
            up_b[i - 1] = c[i - 1];
        }

        up_b[i - 1] =
            min(up_b[i - 1], max_allowed_prev);
    }
    
    // Validate first element
    if (up_b[0] < c[0]) {
        cout << "NO\n";
        return;
    }
    
    long long current_b = c[0];

    if (s[0] == '1' && a[0] != current_b) {
        cout << "NO\n";
        return;
    }
    
    // Forward reconstruction
    vector<long long> b(n);

    b[0] = current_b;
    
    for (int i = 1; i < n; i++) {

        if (s[i] == '1') {

            b[i] = b[i - 1] + a[i];
        }
        else {

            if (c[i] > c[i - 1]) {
                b[i] = c[i];
            }
            else {
                b[i] = up_b[i];
            }
        }
        
        // Safety validation
        if (b[i] > c[i] ||
           (c[i] > c[i - 1] && b[i] != c[i])) {

            cout << "NO\n";
            return;
        }
    }
    
    // Recover original array
    cout << "YES\n";

    a[0] = b[0];

    cout << a[0]
         << (n == 1 ? "" : " ");

    for (int i = 1; i < n; i++) {

        a[i] = b[i] - b[i - 1];

        cout << a[i]
             << (i == n - 1 ? "" : " ");
    }

    cout << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    if (cin >> t) {

        while (t--) {
            solve();
        }
    }

    return 0;
}
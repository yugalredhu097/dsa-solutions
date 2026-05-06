// Problem: Epic Transformation
// Platform: Codeforces
// Problem ID: 1506D
// Link: https://codeforces.com/contest/1506/problem/D
// Approach: Greedy + Frequency Analysis
// Time Complexity: O(n log n)
// Space Complexity: O(1) (excluding input)

/*
Explanation:

We are given an array.

Operation:
We can remove two elements with different values.

Goal:
Minimize remaining elements.

------------------------------------------------

Key Idea:

To maximize removals:
Always remove pairs of different elements.

------------------------------------------------

Observation:

Let:
- max_freq = frequency of most frequent element
- n = total elements

------------------------------------------------

Case 1:
If max_freq > n - max_freq

→ Dominant element cannot be fully paired

Remaining = 2 * max_freq - n

------------------------------------------------

Case 2:
Otherwise:

→ All elements can mostly be paired

Remaining = n % 2

------------------------------------------------

Special Case:
If all elements same → answer = n

------------------------------------------------

Steps:

1. Sort array
2. Count frequencies
3. Find max frequency
4. Apply formula

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        long long max_freq = 0;
        long long current_freq = 1;
        int distinct_count = 1;
        
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                current_freq++;
            } else {
                max_freq = max(max_freq, current_freq);
                current_freq = 1;
                distinct_count++;
            }
        }

        max_freq = max(max_freq, current_freq);
        
        if (distinct_count == 1) {
            cout << n << "\n";
            continue;
        }
        
        if (max_freq > n - max_freq) {
            cout << 2 * max_freq - n << "\n";
        } else {
            cout << n % 2 << "\n";
        }
    }

    return 0;
}
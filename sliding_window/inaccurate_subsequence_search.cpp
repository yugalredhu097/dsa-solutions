// Problem: Inaccurate Subsequence Search
// Link: https://codeforces.com/contest/1955/problem/D
// Approach: Sliding Window + Frequency Maps
// Time Complexity: O(n)
// Space Complexity: O(m)

/*
Explanation:

We are given:

- Array a of size n
- Array b of size m
- Integer k

Goal:

Count how many subarrays of length m in a
contain at least k matching elements with b
(with multiplicity considered).

------------------------------------------------

Key Idea:

Use a sliding window of size m over array a.

We compare frequencies of current window
against required frequencies from b.

------------------------------------------------

Definitions:

mpp[value] = required frequency from b
temp[value] = current window frequency

cnt = number of matched elements
      considering allowed multiplicity

------------------------------------------------

Window Movement:

1. Add new element entering window
2. Remove old element leaving window
3. Update cnt efficiently

------------------------------------------------

If cnt >= k:
This window is valid.

------------------------------------------------

Efficient because:

Each element enters/leaves once.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n), b(m);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        unordered_map<int,int> mpp, temp;

        // Frequency of b
        for (int x : b)
            mpp[x]++;

        int cnt = 0;
        int ans = 0;

        // Initial window
        for (int i = 0; i < m; i++) {

            if (mpp.count(a[i])) {

                temp[a[i]]++;

                if (temp[a[i]] <= mpp[a[i]])
                    cnt++;
            }
        }

        if (cnt >= k)
            ans++;

        int l = 0, r = m - 1;

        while (r < n) {

            // Remove left element
            if (mpp.count(a[l])) {

                if (temp[a[l]] <= mpp[a[l]])
                    cnt--;

                temp[a[l]]--;

                if (temp[a[l]] == 0)
                    temp.erase(a[l]);
            }

            l++;
            r++;

            if (r >= n)
                break;

            // Add right element
            if (mpp.count(a[r])) {

                temp[a[r]]++;

                if (temp[a[r]] <= mpp[a[r]])
                    cnt++;
            }

            if (cnt >= k)
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
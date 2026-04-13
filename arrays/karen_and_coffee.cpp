// Problem: Karen and Coffee
// Link: https://codeforces.com/problemset/problem/816/B
// Approach: Difference Array + Prefix Sum
// Time Complexity: O(n + maxTemp + q)
// Space Complexity: O(maxTemp)

/*
Explanation:

We are given:
- n recipes with temperature ranges [l, r]
- k → minimum required recipes
- q queries asking for range [a, b]

Goal:
For each query, count how many temperatures in [a, b]
are "acceptable" (i.e., covered by at least k recipes).

------------------------------------------------

Key Idea:

1. Use a difference array to mark ranges efficiently:
   diff[l]++
   diff[r+1]--

2. Convert diff → actual count array using prefix sum:
   count[i] = number of recipes covering temperature i

3. Build another prefix sum:
   prefixSum[i] = number of valid temperatures ≤ i

4. For each query [a, b]:
   answer = prefixSum[b] - prefixSum[a-1]

------------------------------------------------

Why this works:

- Range updates → O(1) using difference array
- Query answering → O(1) using prefix sums

------------------------------------------------

This avoids brute force O(n*q) and makes it efficient.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k, q;
    cin >> n >> k >> q;

    const int MAXTEMP = 200001;

    vector<int> diff(MAXTEMP, 0);

    // Mark ranges using difference array
    for (int i = 0; i < n; i++) {

        int l, r;
        cin >> l >> r;

        diff[l]++;
        diff[r + 1]--;
    }

    // Build count array
    vector<int> count(MAXTEMP, 0);

    count[0] = diff[0];

    for (int i = 1; i < MAXTEMP; i++) {
        count[i] = count[i - 1] + diff[i];
    }

    // Build prefix sum of valid temperatures
    vector<int> prefixSum(MAXTEMP, 0);

    for (int i = 1; i < MAXTEMP; i++) {

        prefixSum[i] = prefixSum[i - 1];

        if (count[i] >= k)
            prefixSum[i]++;
    }

    // Answer queries
    while (q--) {

        int a, b;
        cin >> a >> b;

        cout << prefixSum[b] - prefixSum[a - 1] << endl;
    }

    return 0;
}
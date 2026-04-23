// Problem: Alphabet City
// Link: https://codeforces.com/contest/2181/problem/A
// Approach: Frequency Counting + Simulation
// Time Complexity: O(total characters)
// Space Complexity: O(alphabet size)

/*
Explanation:

We are given:

- n strings
- integer m

For each string sign[i]:

Remove its characters temporarily from the global pool
of all characters from other strings.

Goal:
Determine how many additional complete copies of sign[i]
can still be formed from remaining characters.

If impossible or required copies exceed m:
answer = -1

Else:
answer = m - requiredCopies

------------------------------------------------

Key Idea:

1. Count frequency of all characters globally.

2. For each string:
   - Remove its own letters temporarily
   - Count needed frequency for that string
   - Compare against remaining pool

For each character:

needed = temp[ch]
available = mpp[ch]

Copies required =
ceil(needed / available)

Take maximum over all characters.

------------------------------------------------

If any required character unavailable:
Impossible.

------------------------------------------------

Then restore removed characters.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<string> sign(n);

    for (int i = 0; i < n; i++) {
        cin >> sign[i];
    }

    unordered_map<char,int> mpp;

    // Global frequency
    for (int i = 0; i < n; i++) {
        for (char c : sign[i]) {
            mpp[c]++;
        }
    }

    vector<int> ans(n);
    unordered_map<char,int> temp;

    for (int i = 0; i < n; i++) {

        temp.clear();

        // Remove current string from global pool
        for (char c : sign[i]) {
            mpp[c]--;
            if (mpp[c] == 0)
                mpp.erase(c);

            temp[c]++;
        }

        int maxi = 1;
        bool possible = true;

        for (auto &it : temp) {

            char ch = it.first;
            int need = it.second;

            if (!mpp.count(ch)) {
                possible = false;
                break;
            }

            int avail = mpp[ch];

            if (need > avail) {
                maxi = max(maxi, (need + avail - 1) / avail);
            }
        }

        if (!possible || maxi > m)
            ans[i] = -1;
        else
            ans[i] = m - maxi;

        // Restore frequencies
        for (char c : sign[i]) {
            mpp[c]++;
        }
    }

    for (int x : ans)
        cout << x << " ";

    return 0;
}
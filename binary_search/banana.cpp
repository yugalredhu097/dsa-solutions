// Problem: Banana
// Link: https://codeforces.com/contest/335/problem/A
// Approach: Binary Search on Answer + Frequency Construction
// Time Complexity: O(26 log n)
// Space Complexity: O(26)

/*
Explanation:

We are given:

- String s
- Integer n

Need to create a string of length n using characters
from s such that:

Each chosen character can represent at most k copies
of its original frequency.

Goal:
Find minimum possible k,
then construct any valid answer string.

------------------------------------------------

Key Idea:

If a character appears freq times,
and one sheet can hold k copies,

Required sheets for that character:

ceil(freq / k)

Total required characters must be <= n.

------------------------------------------------

This condition is monotonic:

If k works,
any larger k also works.

So use binary search on k.

------------------------------------------------

After finding minimum k:

For each character:
append ceil(freq / k) copies

Then pad remaining length with 'a'.

------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<pair<int,char>> &freq, int mid, int n) {

    int elements = 0;

    for (auto &p : freq) {
        elements += (p.first + mid - 1) / mid; // ceil division
    }

    return elements <= n;
}

int main() {

    string s;
    cin >> s;

    int n;
    cin >> n;

    unordered_map<char,int> mpp;

    for (char c : s)
        mpp[c]++;

    vector<pair<int,char>> freq;

    for (auto &it : mpp) {
        freq.push_back({it.second, it.first});
    }

    sort(freq.begin(), freq.end());

    int low = 1;
    int high = freq.back().first;
    int sheets = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (ispossible(freq, mid, n)) {
            sheets = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (sheets == -1) {
        cout << -1 << endl;
        return 0;
    }

    string ans = "";

    for (auto &p : freq) {

        int count = (p.first + sheets - 1) / sheets;

        while (count--) {
            ans += p.second;
        }
    }

    while ((int)ans.size() < n)
        ans += 'a';

    cout << sheets << endl;
    cout << ans << endl;

    return 0;
}
// Problem: All Lengths Subtraction
// Link: https://codeforces.com/problemset/problem/2143/A
// Approach: Simulation + Segment Checking
// Time Complexity: O(n^2)
// Space Complexity: O(n)

/*
Explanation:

We are given an array v of size n.

Goal:
Check if we can perform operations where for each length i (1 → n),
we subtract 1 from a contiguous segment of exactly length i that
contains the maximum element.

Steps:

1. Find the index of the maximum element.
2. Determine the full segment of equal values around this maximum.
3. For operation length i:
   - If the segment length equals i,
     subtract 1 from every element in that segment.
   - Otherwise the process is impossible.
4. Repeat for lengths from 1 to n.

If all operations succeed → print "YES",
otherwise → print "NO".

Key Idea:
At each step we ensure the largest block of equal elements
matches the required operation length.
*/

#include <bits/stdc++.h>
using namespace std;

pair<int,int> max_ele_lenght(vector<int> &v, int mx){

    int n = v.size();

    int l = 0, r = 0;

    int i = mx;

    while (i < n && v[i] == v[mx]) {
        i++;
    }

    r = i - 1;

    i = mx;

    while (i >= 0 && v[i] == v[mx]) {
        i--;
    }

    l = i + 1;

    return {l, r};
}

int main(){

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        bool flag = true;

        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<int> v2 = v;

        int mx = max_element(v.begin(), v.end()) - v.begin();

        for (int i = 1; i <= n; i++) {

            pair<int,int> p = max_ele_lenght(v2, mx);

            if (p.second - p.first + 1 == i) {

                for (int j = p.first; j <= p.second; j++) {
                    v2[j]--;
                }
            }
            else {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
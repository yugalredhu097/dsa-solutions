// Problem: Balls Game
// Platform: Codeforces
// Problem ID: 430B
// Link: https://codeforces.com/contest/430/problem/B
// Approach: Simulation + Two Pointer Expansion (Palindrome-like)
// Time Complexity: O(n^2)
// Space Complexity: O(1)

/*
Explanation:

We are given:
- Array of colors
- A target color x

Goal:
Find maximum balls removed by inserting x optimally.

------------------------------------------------

Key Idea:

We try every position where two consecutive x exist.

From that center, expand outward like palindrome:

- If both sides match → continue
- Remove blocks of same color
- Handle chain reactions carefully

------------------------------------------------

Function "terminator":

- Expands from center (l, r)
- Handles multiple cases:
  - Continuous same values
  - Boundary conditions
  - Stops when mismatch occurs

Returns length of removable segment.

------------------------------------------------

Main Logic:

1. Find all adjacent positions where v[i] == x
2. Try expansion from there
3. Track maximum result

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int terminator(vector<int> &v, int l, int r){
    l--;
    r++;
    int n = v.size();

    while(l >= 0 && r < n){
        if(v[l] == v[r]){

            if(l-1 >= 0 && r+1 < n && v[l-1] == v[l] && v[r+1] == v[r]){
                l -= 2;
                r += 2;
            }
            else if(l-1 >= 0 && r+1 < n && v[l-1] != v[l] && v[r+1] == v[r]){
                l--;
                r += 2;
            }
            else if(l-1 >= 0 && r+1 < n && v[l-1] == v[l] && v[r+1] != v[r]){
                l -= 2;
                r++;
            }
            else if(l-1 >= 0 && r+1 < n && v[l-1] != v[l] && v[r+1] != v[r]){
                break;
            }
            else if(l-1 >= 0 && v[l-1] != v[l] && r == n-1){
                break;
            }
            else if(l-1 >= 0 && v[l-1] == v[l] && r == n-1){
                l -= 2;
                r++;
            }
            else if(r+1 < n && v[r+1] != v[r] && l == 0){
                break;
            }
            else if(r+1 < n && v[r+1] == v[r] && l == 0){
                l--;
                r += 2;
            }
        }
        else break;
    }

    return r - l - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 0;

    for(int i = 1; i < n; i++){
        if(v[i-1] == x && v[i] == x){
            ans = max(ans, terminator(v, i-1, i));
        }
    }

    cout << ans << endl;

    return 0;
}
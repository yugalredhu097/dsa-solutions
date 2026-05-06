// Problem: Awoo's Favorite Number
// Platform: Codeforces
// Problem ID: 1697C
// Link: https://codeforces.com/contest/1697/problem/C
// Approach: Greedy + Relative Order Preservation + Position Constraints
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given two strings s and t.

Allowed operation:
- Swap adjacent characters, but:
  'a' can only move left
  'c' can only move right
  'b' acts as a placeholder

------------------------------------------------

Key Idea:

1. Remove all 'b' from both strings
   → Remaining sequences must match

If not equal → impossible

------------------------------------------------

2. Track positions:

- 'a' positions:
  In s, 'a' can only move LEFT
  So position in s must be <= position in t

- 'c' positions:
  In s, 'c' can only move RIGHT
  So position in s must be >= position in t

------------------------------------------------

If all constraints satisfied → YES
Else → NO

------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        // Remove 'b' and compare
        string s_filtered = "", t_filtered = "";

        for(char c : s) if(c != 'b') s_filtered += c;
        for(char c : t) if(c != 'b') t_filtered += c;

        if(s_filtered != t_filtered){
            cout << "NO\n";
            continue;
        }

        // Store positions
        vector<int> As, At, Cs, Ct;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a') As.push_back(i);
            if(s[i] == 'c') Cs.push_back(i);
            if(t[i] == 'a') At.push_back(i);
            if(t[i] == 'c') Ct.push_back(i);
        }

        bool pos = true;

        // Check 'a' constraint
        for(int i = 0; i < As.size(); i++){
            if(As[i] > At[i]){
                pos = false;
                break;
            }
        }

        // Check 'c' constraint
        for(int i = 0; i < Cs.size(); i++){
            if(Cs[i] < Ct[i]){
                pos = false;
                break;
            }
        }

        if(pos) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
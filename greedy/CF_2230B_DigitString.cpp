// Problem: Digit String
// Platform: Codeforces
// Problem ID: 2230B
// Link: https://codeforces.com/contest/2230/problem/B
// Approach: Greedy Counting
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Explanation:

We process a digit string.

Goal:
Maximize valid contributions based on
specific digit matching rules.

------------------------------------------------

Key Idea:

- Digit '4' directly contributes to answer
- Digits '1' and '3' can later pair with
  another digit to contribute

------------------------------------------------

Greedy Strategy:

Traverse string from left to right.

Cases:

1. If digit == '4'
   → immediate contribution

2. If digit == '1'
   → store count of ones

3. If digit == '3'
   → store count of threes

4. Otherwise:
   - Prefer using available '1'
   - Else use available '3'

Each successful pairing increases answer.

------------------------------------------------

Why Greedy Works?

Using earlier available digits immediately
maximizes total valid operations.

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

        string s;
        cin >> s;

        int ans = 0;

        int one = 0;
        int three = 0;

        for(int i = 0; i < s.size(); i++){

            // Direct contribution
            if(s[i] == '4'){
                ans++;
            }

            // Store count of 1
            else if(s[i] == '1'){
                one++;
            }

            // Store count of 3
            else if(s[i] == '3'){
                three++;
            }

            // Try pairing
            else{

                if(one > 0){
                    one--;
                    ans++;
                }
                else if(three > 0){
                    three--;
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
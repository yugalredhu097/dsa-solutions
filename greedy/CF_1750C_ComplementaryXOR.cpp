// Problem: Complementary XOR
// Platform: Codeforces
// Problem ID: 1750C
// Link: https://codeforces.com/problemset/problem/1750/C
// Approach: Greedy Construction + Parity Handling
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We are given two binary strings:
- a
- b

Allowed Operation:
Choose a segment [l, r]
and flip all bits in that range.

Goal:
Make strings satisfy required XOR condition.

------------------------------------------------

Key Observation:

For every position:

Either:
- all positions are same
OR
- all positions are different

Otherwise answer is impossible.

------------------------------------------------

Cases:

1. Mixed same/different positions:
   → Impossible

2. All same:
   → Need even number of flips

3. All different:
   → Need odd number of flips

------------------------------------------------

Greedy Construction:

For every '1' in string a:
- Flip that single position
- This converts a into all zeros

Track total flips parity.

------------------------------------------------

Parity Fix:

If parity becomes incorrect:
Apply 3 extra operations:

[1, n]
[1, 1]
[2, n]

This changes parity while preserving validity.

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

        string a, b;
        cin >> a >> b;

        vector<pair<int,int>> ans;

        int same = 0;

        for(int i = 0; i < n; i++){
            if(a[i] == b[i]) same++;
        }

        // Mixed positions → impossible
        if(same != 0 && same != n){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int bFlips = (same == 0);

        // Flip all '1's individually
        for(int i = 0; i < n; i++){
            if(a[i] == '1'){
                ans.push_back({i + 1, i + 1});
                bFlips++;
            }
        }

        // Fix parity if needed
        if(bFlips % 2 != 0){
            ans.push_back({1, n});
            ans.push_back({1, 1});
            ans.push_back({2, n});
        }

        cout << ans.size() << endl;

        for(pair<int,int> p : ans){
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}
// Problem: Sasha and the Casino
// Platform: Codeforces
// Problem ID: 1929C
// Link: https://codeforces.com/contest/1929/problem/C
// Approach: Greedy Simulation + Mathematical Threshold Building
// Time Complexity: O(x)
// Space Complexity: O(1)

/*
Explanation:

We are given:

- k → multiplier
- x → number of losses allowed
- a → initial coins

Goal:
Determine if Sasha can guarantee profit strategy.

------------------------------------------------

Key Idea:

We simulate the minimum required coins (threshold)
to survive x losses.

At each step:
- We bet an amount such that even after losing,
  we can recover using multiplier k.

------------------------------------------------

Observation:

To safely proceed:
bet > (total previous loss) / (k - 1)

So:
bet = threshold / (k - 1) + 1

------------------------------------------------

We accumulate total losses (threshold):

threshold += bet

If at any point threshold exceeds limit → break early

------------------------------------------------

Final Check:

If total required threshold <= a → YES
Else → NO

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
        long long k, x, a;
        cin >> k >> x >> a;

        long long bet = 1;
        long long threshold = 0;
        bool overflow = false;

        for(int i = 0; i <= x; i++){
            threshold += bet;

            if(threshold > 1e18){
                overflow = true;
                break;
            }

            if(i < x){
                bet = threshold / (k - 1) + 1;
            }
        }

        if(!overflow && a >= threshold){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
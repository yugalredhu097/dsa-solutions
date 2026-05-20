// Problem: Almost All Multiples
// Platform: Codeforces
// Problem ID: 1758C
// Link: https://codeforces.com/contest/1758/problem/C
// Approach: Greedy Construction + Divisibility
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We need to construct a permutation p such that:

- p[1] = x
- p[n] = 1

And for every index i:
p[i] is divisible by i.

------------------------------------------------

Key Idea:

Start with identity permutation:
p[i] = i

Then:
- Place x at position 1
- Place 1 at position n

Now we must ensure divisibility condition.

------------------------------------------------

Observation:

We build a chain:

x -> next divisor -> ... -> n

Where:
- next number is divisible by current x
- n is divisible by next number

This preserves:
p[i] % i == 0

------------------------------------------------

Greedy Strategy:

While current x != n:
- Find smallest valid multiple j
- Set:
    p[x] = j
    p[j] = n (temporarily)
- Move x = j

------------------------------------------------

If n is not divisible by original x:
answer impossible.

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

        int n, x;
        cin >> n >> x;

        // Impossible case
        if(n % x != 0){
            cout << "-1\n";
            continue;
        }

        vector<int> ans(n + 1, 0);

        ans[1] = x;
        ans[n] = 1;

        int i = 2;

        while(i < n){

            if(i == x){

                ans[x] = n;

                int j = i + 1;

                // Find next valid divisor
                while(j < n &&
                     (j % x != 0 || n % j != 0)){
                    j++;
                }

                if(j == n){
                    break;
                }
                else{
                    ans[x] = j;
                    ans[j] = n;

                    x = j;
                    i = j;
                }
            }
            else{
                i++;
            }
        }

        // Fill remaining positions with identity
        for(int i = 1; i <= n; i++){

            if(ans[i] == 0)
                cout << i << " ";
            else
                cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}